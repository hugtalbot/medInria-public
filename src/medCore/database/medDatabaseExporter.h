/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medCoreExport.h>
#include <QtCore>

#include <medJobItem.h>

class medAbstractData;
class medDatabaseExporterPrivate;

class MEDCORE_EXPORT medDatabaseExporter : public medJobItem
{
    Q_OBJECT

public:
     medDatabaseExporter(medAbstractData * data, const QString & filename, const QString & writer);
    ~medDatabaseExporter();

    /**
     * @brief Starts the job and writes to the file system.
     *
     * @param void
     * @todo enrich the signals in the exporter (the writer progress signal is not forwarded to the explorer)
    */
    void run();

private:
    medDatabaseExporterPrivate *d;
};

