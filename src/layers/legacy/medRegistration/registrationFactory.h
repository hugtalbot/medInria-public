/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once
#include <QObject>
#include <itkImageRegistrationFactory.h>
#include <itkTransform.h>
#include <medRegistrationExport.h>


class registrationFactoryPrivate;

class MEDREGISTRATIONFACTORY_EXPORT registrationFactory : public QObject
{
    Q_OBJECT

public:

    typedef itk::Image< float, 3 > RegImageType;

    static registrationFactory * instance();

    void setItkRegistrationFactory(itk::ImageRegistrationFactory<RegImageType>::Pointer registrationFactory);

    itk::ImageRegistrationFactory<RegImageType>::Pointer getItkRegistrationFactory();

    itk::GeneralTransform<double,3>::Pointer getGeneralTransform();

    unsigned int addTransformation(itk::Transform<double,3,3>::Pointer arg, QString methodParameters);

    public slots:
        void reset();

    signals:
        void transformationAdded(int,QString);
        void transformationStackReset();

protected:
    /**
    * @brief Constructor, not to be used by users.
    *
    * Use the instance() method instead to get a singleton.
    *
    * @param void
    */
    registrationFactory();

    /**
    * @brief Destructor, not to be used by users.
    *
    * The singleton will be deleted at application closing time.
    *
    * @param void
    */
    ~registrationFactory();

private:

    static registrationFactory* s_instance;

    registrationFactoryPrivate * d;
};


