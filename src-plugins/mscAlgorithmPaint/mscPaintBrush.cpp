
#include <itkAddImageFilter.h>
#include <itkImage.h>
#include <itkImageRegionIterator.h>
#include <itkRGBPixel.h>
#include "itkScalarToRGBColormapImageFilter.h"
#include "mscPaintBrush.h"

namespace msc
{

class mscPaintBrushPrivate
{
public:
    ~mscPaintBrushPrivate()
    {
        slice = nullptr;
    }

    Mask2dType::Pointer slice;
    bool isMaster; //true when the ROI is new or has been modified (for interpolation)
};

mscPaintBrush::mscPaintBrush(Mask2dType::Pointer slice, int id, bool isMaster, medAbstractRoi* parent)
    : medAbstractRoi(parent),
      d(new mscPaintBrushPrivate)
{
    setIdSlice(id);
    d->slice = slice;
    setMasterRoi(isMaster);
}

mscPaintBrush::~mscPaintBrush()
{
    delete d;
    d = nullptr;
}

Mask2dType::Pointer mscPaintBrush::getSlice()
{
    return d->slice;
}

void mscPaintBrush::setSlice(Mask2dType::Pointer slice)
{
    d->slice = slice;
}

void mscPaintBrush::updateMask(Mask2dType::Pointer updatedSlice)
{
    typedef itk::AddImageFilter <Mask2dType, Mask2dType>
      AddImageFilterType;

    AddImageFilterType::Pointer addFilter = AddImageFilterType::New ();
    addFilter->SetInput1(d->slice);
    addFilter->SetInput2(updatedSlice);
    addFilter->Update();
    d->slice = nullptr;
    d->slice = addFilter->GetOutput();
}

void mscPaintBrush::setRightColor()
{
}

void mscPaintBrush::Off()
{

}

void mscPaintBrush::On()
{

}

bool mscPaintBrush::isVisible()
{
    return false;
}

void mscPaintBrush::forceInvisibilityOn()
{

}

void mscPaintBrush::forceInvisibilityOff()
{

}

QString mscPaintBrush::info()
{
    return QString();
}

QString mscPaintBrush::type()
{
    return QString();
}

void mscPaintBrush::computeRoiStatistics()
{

}

bool mscPaintBrush::canRedo()
{
    return false;
}

bool mscPaintBrush::canUndo()
{
    return false;
}

void mscPaintBrush::undo()
{

}

void mscPaintBrush::redo()
{

}

void mscPaintBrush::saveState()
{

}

bool mscPaintBrush::copyROI(medAbstractView *view)
{
    return false;
}

medAbstractRoi *mscPaintBrush::getCopy(medAbstractView *view)
{
    return nullptr;
}

QList<medAbstractRoi *> *mscPaintBrush::interpolate(medAbstractRoi *roi)
{
    return nullptr;
}
}
