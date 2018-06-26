
#include <itkImage.h>
#include "mscPaintBrush.h"

namespace msc
{

mscPaintBrush::mscPaintBrush(medAbstractRoi* parent)

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
