/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractSubstractImageProcessPlugin.h>

class medItkSubstractImageProcessPlugin : public medAbstractSubstractImageProcessPlugin
{
    Q_OBJECT
    Q_INTERFACES(medAbstractSubstractImageProcessPlugin)
    Q_PLUGIN_METADATA(IID "fr.inria.medItkSubstractImageProcessPlugin" FILE "medItkSubstractImageProcessPlugin.json")

public:
     medItkSubstractImageProcessPlugin(void) {}
    virtual ~medItkSubstractImageProcessPlugin(void) {}

public:
    void initialize(void);
    void uninitialize(void);
};