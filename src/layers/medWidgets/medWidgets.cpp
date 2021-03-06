/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medWidgets.h>

namespace medWidgets
{
namespace pluginManager
{
    void initialize(const QString& path, bool verbose)
    {
        for(QString const& realpath : path.split(';'))
        {
            if(realpath.isEmpty())
                break;
        }
    }
}

namespace generic
{
    namespace _private
    {
        medAbstractProcessPresenterFactory factory;
    }

    medAbstractProcessPresenterFactory& presenterFactory()
    {
        return _private::factory;
    }
}

namespace morphomathOperation
{
    namespace erodeImage
    {
        namespace _private
        {
            medAbstractErodeImageProcessPresenterFactory factory;
        }

        medAbstractErodeImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace dilateImage
    {
        namespace _private
        {
            medAbstractDilateImageProcessPresenterFactory factory;
        }

        medAbstractDilateImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace openingImage
    {
        namespace _private
        {
            medAbstractOpeningImageProcessPresenterFactory factory;
        }

        medAbstractOpeningImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace closingImage
    {
        namespace _private
        {
            medAbstractClosingImageProcessPresenterFactory factory;
        }

        medAbstractClosingImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }
}

namespace arithmeticOperation
{
    namespace addImage
    {
        namespace _private
        {
            medAbstractAddImageProcessPresenterFactory factory;
        }

        medAbstractAddImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace subtractImage
    {
        namespace _private
        {
            medAbstractSubtractImageProcessPresenterFactory factory;
        }

        medAbstractSubtractImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace multiplyImage
    {
        namespace _private
        {
            medAbstractMultiplyImageProcessPresenterFactory factory;
        }

        medAbstractMultiplyImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace divideImage
    {
        namespace _private
        {
            medAbstractDivideImageProcessPresenterFactory factory;
        }

        medAbstractDivideImageProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }
}

namespace maskImage
{
    namespace _private
    {
        medAbstractMaskImageProcessPresenterFactory factory;
    }

    medAbstractMaskImageProcessPresenterFactory& presenterFactory()
    {
        return _private::factory;
    }
}

namespace dwiMasking
{
    namespace _private
    {
        medAbstractDWIMaskingProcessPresenterFactory factory;
    }

    medAbstractDWIMaskingProcessPresenterFactory& presenterFactory()
    {
        return _private::factory;
    }
}

namespace diffusionModelEstimation
{
    namespace _private
    {
        medAbstractDiffusionModelEstimationProcessPresenterFactory factory;
    }

    medAbstractDiffusionModelEstimationProcessPresenterFactory& presenterFactory()
    {
        return _private::factory;
    }
}

namespace diffusionScalarMaps
{
    namespace _private
    {
        medAbstractDiffusionScalarMapsProcessPresenterFactory factory;
    }

    medAbstractDiffusionScalarMapsProcessPresenterFactory& presenterFactory()
    {
        return _private::factory;
    }
}

namespace tractography
{
    namespace _private
    {
        medAbstractTractographyProcessPresenterFactory factory;
    }

    medAbstractTractographyProcessPresenterFactory& presenterFactory()
    {
        return _private::factory;
    }
}

namespace singleFilterOperation
{

    namespace addFilter
    {
        namespace _private
        {
            medAbstractAddFilterProcessPresenterFactory factory;
        }

        medAbstractAddFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace divideFilter
    {
        namespace _private
        {
            medAbstractDivideFilterProcessPresenterFactory factory;
        }

        medAbstractDivideFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace gaussianFilter
    {
        namespace _private
        {
            medAbstractGaussianFilterProcessPresenterFactory factory;
        }

        medAbstractGaussianFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace invertFilter
    {
        namespace _private
        {
            medAbstractInvertFilterProcessPresenterFactory factory;
        }

        medAbstractInvertFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace medianFilter
    {
        namespace _private
        {
            medAbstractMedianFilterProcessPresenterFactory factory;
        }

        medAbstractMedianFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace multiplyFilter
    {
        namespace _private
        {
            medAbstractMultiplyFilterProcessPresenterFactory factory;
        }

        medAbstractMultiplyFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace normalizeFilter
    {
        namespace _private
        {
            medAbstractNormalizeFilterProcessPresenterFactory factory;
        }

        medAbstractNormalizeFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace shrinkFilter
    {
        namespace _private
        {
            medAbstractShrinkFilterProcessPresenterFactory factory;
        }

        medAbstractShrinkFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace subtractFilter
    {
        namespace _private
        {
            medAbstractSubtractFilterProcessPresenterFactory factory;
        }

        medAbstractSubtractFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace windowingFilter
    {
        namespace _private
        {
            medAbstractWindowingFilterProcessPresenterFactory factory;
        }

        medAbstractWindowingFilterProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace imageDenoising
    {
        namespace _private
        {
            medAbstractImageDenoisingProcessPresenterFactory factory;
        }

        medAbstractImageDenoisingProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace relaxometryEstimation
    {
        namespace _private
        {
            medAbstractRelaxometryEstimationProcessPresenterFactory factory;
        }

        medAbstractRelaxometryEstimationProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }

    namespace symmetryAlignment
    {
        namespace _private
        {
            medAbstractSymmetryPlaneAlignmentProcessPresenterFactory factory;
        }

        medAbstractSymmetryPlaneAlignmentProcessPresenterFactory& presenterFactory()
        {
            return _private::factory;
        }
    }
}

} // end of medWidgets

