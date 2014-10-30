/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medFilteringWorkspace.h>

#include <dtkCore/dtkAbstractProcessFactory.h>

#include <medMetaDataKeys.h>
#include <medProcessSelectorToolBox.h>
#include <medTabbedViewContainers.h>
#include <medToolBoxFactory.h>
#include <medViewContainer.h>
#include <medFilteringAbstractToolBox.h>
#include <medAbstractData.h>
#include <medDataManager.h>

#include <medJobManager.h>

#include <medAbstractView.h>
#include <medAbstractLayeredView.h>

#include <medViewParameterGroup.h>
#include <medLayerParameterGroup.h>

#include <medAbstractFilteringProcess.h>
#include <medTriggerParameter.h>
#include <medViewContainerSplitter.h>

class medFilteringWorkspacePrivate
{
public:
    QPointer<medProcessSelectorToolBox> filteringToolBox;
    medViewContainer *inputContainer;
    medViewContainer *outputContainer;

    medAbstractData *filterInput;
    medAbstractData *filterOutput;

    dtkSmartPointer <medAbstractFilteringProcess> process;
};

medFilteringWorkspace::medFilteringWorkspace(QWidget *parent): medAbstractWorkspace (parent), d(new medFilteringWorkspacePrivate)
{
    d->filterInput = NULL;
    d->filterOutput = NULL;

    d->filteringToolBox = new medProcessSelectorToolBox(parent);
    d->filteringToolBox->setTitle("Filtering");

    this->addToolBox(d->filteringToolBox);

    QStringList implementations = dtkAbstractProcessFactory::instance()->implementations("medAbstractFilteringProcess");
    d->filteringToolBox->setAvailableProcesses(implementations);

    medViewParameterGroup *viewGroup1 = new medViewParameterGroup("View Group 1", this, this->identifier());
    viewGroup1->setLinkAllParameters(true);
    viewGroup1->removeParameter("DataList");

    medLayerParameterGroup *layerGroup1 = new medLayerParameterGroup("Layer Group 1", this,  this->identifier());
    layerGroup1->setLinkAllParameters(true);

    connect(d->filteringToolBox, SIGNAL(processSelected(QString)), this, SLOT(setupProcess(QString)));
}

medFilteringWorkspace::~medFilteringWorkspace()
{
    delete d;
    d = NULL;
}

/**
 * @brief sets up all the signal/slot connections when Viewer is switched to this workspace
 */
void medFilteringWorkspace::setupTabbedViewContainer()
{
//    if ( !this->tabbedViewContainers()->count() )
//    {
//        d->inputContainer = this->tabbedViewContainers()->addContainerInTab(this->name());
//        QLabel *inputLabel = new QLabel("INPUT");
//        inputLabel->setAlignment(Qt::AlignCenter);
//        d->inputContainer->setDefaultWidget(inputLabel);

//        d->inputContainer->setClosingMode(medViewContainer::CLOSE_VIEW_ONLY);
//        d->inputContainer->setUserSplittable(false);
//        d->inputContainer->setMultiLayered(false);

//        d->outputContainer = d->inputContainer->splitVertically();
//        QLabel *outputLabel = new QLabel("OUTPUT");
//        outputLabel->setAlignment(Qt::AlignCenter);
//        d->outputContainer->setDefaultWidget(outputLabel);
//        d->outputContainer->setClosingMode(medViewContainer::CLOSE_VIEW_ONLY);
//        d->outputContainer->setUserSplittable(false);
//        d->outputContainer->setMultiLayered(false);
//        d->outputContainer->setUserOpenable(false);

//        connect(d->inputContainer, SIGNAL(viewContentChanged()), this, SLOT(updateInput()));
//        connect(d->inputContainer, SIGNAL(viewRemoved()), this, SLOT(updateInput()));

//        this->tabbedViewContainers()->lockTabs();
//        this->tabbedViewContainers()->hideTabBar();
//        d->inputContainer->setSelected(true);
//        d->outputContainer->setSelected(false);
//    }
}


void medFilteringWorkspace::setupProcess(QString process)
{
    d->process = dynamic_cast<medAbstractFilteringProcess*>(dtkAbstractProcessFactory::instance()->create(process));
    if(d->process)
    {
        d->filteringToolBox->setProcessToolbox(d->process->toolbox());
        d->process->setInputImage(d->filterInput);
        connect(d->process->runParameter(), SIGNAL(triggered()), this, SLOT(startProcess()));
        this->tabbedViewContainers()->setSplitter(0, d->process->viewContainerSplitter());
    }
}

void medFilteringWorkspace::updateInput()
{
    if(!d->inputContainer->view())
    {
        d->filterInput = NULL;
        return;
    }
    medAbstractLayeredView *inputView = dynamic_cast<medAbstractLayeredView *>(d->inputContainer->view());
    if(!inputView)
    {
        qWarning() << "Non layered view are not supported in filtering workspace yet.";
        d->filterInput = NULL;
        return;
    }
    d->filterInput = inputView->layerData(inputView->currentLayer());

    if(d->process)
        d->process->setInputImage(d->filterInput);
}

/**
 * @brief adds metadata to the output and emits a signal outputDataChanged(medAbstractData *)
 */
void medFilteringWorkspace::handleProcessOutput()
{
//    if(d->filteringToolBox.isNull())
//        return;

//    d->filterOutput = d->process->output();
//    if ( !d->filterOutput )
//        return;

//    if (! d->filterOutput->hasMetaData(medMetaDataKeys::SeriesDescription.key()))
//    {
//        QString newSeriesDescription = d->filterInput->metadata ( medMetaDataKeys::SeriesDescription.key() );
//        newSeriesDescription += " filtered";
//        d->filterOutput->addMetaData ( medMetaDataKeys::SeriesDescription.key(), newSeriesDescription );
//    }

//    foreach ( QString metaData, d->filterInput->metaDataList() )
//        if (!d->filterOutput->hasMetaData(metaData))
//            d->filterOutput->addMetaData ( metaData, d->filterInput->metaDataValues ( metaData ) );

//    foreach ( QString property, d->filterInput->propertyList() )
//        d->filterOutput->addProperty ( property,d->filterInput->propertyValues ( property ) );

//    QString generatedID = QUuid::createUuid().toString().replace("{","").replace("}","");
//    d->filterOutput->setMetaData ( medMetaDataKeys::SeriesID.key(), generatedID );

//    medDataManager::instance()->importData(d->filterOutput);

//    d->outputContainer->addData(d->filterOutput);
}

bool medFilteringWorkspace::isUsable()
{
    medToolBoxFactory * tbFactory = medToolBoxFactory::instance();
    return (tbFactory->toolBoxesFromCategory("filtering").size()!=0);
}



void medFilteringWorkspace::startProcess()
{
    if(!d->process)
        return;

    medRunnableProcess *runProcess = new medRunnableProcess(d->process, d->process->name());
    connect (runProcess, SIGNAL (success()),this,SLOT(enableSelectorToolBox()));
    connect (runProcess, SIGNAL (failure()),this,SLOT(enableSelectorToolBox()));
    connect (runProcess, SIGNAL (success()),this,SLOT(handleProcessOutput()));

    runProcess->start();
}
