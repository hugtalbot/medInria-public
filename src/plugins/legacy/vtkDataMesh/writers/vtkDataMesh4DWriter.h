/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <dtkCoreSupport/dtkAbstractDataWriter.h>

#include <vtkDataMeshPluginExport.h>
class vtkDataManagerWriter;


/**
    \class vtkDataMesh4DWriter
    \brief This class implements the writing process of a sequence
    (series) of meshes in vtk format.

    It make extensive use of the vtkDataManager class and API (in
    vtkINRIA3D repository). The ouput file is home-made and xml-based,
    it derives from the API described in vtkDataManagerReader class.

    The default extension (and the only extension currently wrote) is
    *.v4d. The xml-based file lists a series of vtk files where time
    tags have to be populated (file paths are relative).

    \see vtkDataMesh4D vtkDataManagerWriter vtkMetaDataSetSequence
    \author Nicolas Toussaint
*/


class VTKDATAMESHPLUGIN_EXPORT vtkDataMesh4DWriter : public dtkAbstractDataWriter
{
    Q_OBJECT

public:
             vtkDataMesh4DWriter();
    virtual ~vtkDataMesh4DWriter();

    virtual QStringList handled() const;
    static  QStringList s_handled();


    virtual QString description() const;
    virtual QString identifier() const;

    static bool registered();

    virtual QStringList supportedFileExtensions(void) const;

public slots:
    bool write    (const QString& path);
    bool canWrite (const QString& path);

 protected:
    vtkDataManagerWriter* writer;

private:
        static const char ID[];
};


dtkAbstractDataWriter *createVtkDataMesh4DWriter();


