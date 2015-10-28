/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractMorphomathOperationProcessPresenter.h>

#include <dtkCore>

#include <medAbstractOpeningImageProcess.h>

#include <medCoreExport.h>

class MEDCORE_EXPORT medAbstractOpeningImageProcessPresenter: public medAbstractMorphomathOperationProcessPresenter
{
    Q_OBJECT
public:
    medAbstractOpeningImageProcessPresenter(medAbstractOpeningImageProcess *parent)
        : medAbstractMorphomathOperationProcessPresenter(parent)
    {
        m_process = parent;
    }
    virtual medAbstractOpeningImageProcess* process() const
    {
        return m_process;
    }

private:
    medAbstractOpeningImageProcess *m_process;
};
