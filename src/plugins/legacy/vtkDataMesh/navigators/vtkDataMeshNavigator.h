/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractNavigator.h>
#include <QFormLayout>
#include <QSlider>
#include <QWidget>

class vtkDataMeshNavigatorPrivate;

class vtkDataMeshNavigator: public medAbstractNavigator
{
    Q_OBJECT

public:
    vtkDataMeshNavigator(medAbstractView* parent);
    virtual ~vtkDataMeshNavigator();

public:
    virtual QString  identifier() const;
    static QString  s_identifier();
    static bool registered();
    virtual QStringList handled(void) const;
    virtual QString description() const;
    virtual QList<medAbstractParameterL*> linkableParameters();
    virtual QList<medBoolParameterL*> mouseInteractionParameters();

public slots:
    void updateWidgets();

    void enableDepthPeeling(bool);

protected:
    virtual QWidget * buildToolBoxWidget();
    virtual QWidget * buildToolBarWidget();

private:
    vtkDataMeshNavigatorPrivate *d;

};


