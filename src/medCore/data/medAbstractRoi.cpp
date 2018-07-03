#include "medAbstractRoi.h"

class medAbstractRoiPrivate
{
public:
    unsigned char orientation;
    unsigned int idSlice;
    bool isSelected;
    RoiStatistics stats;
};

medAbstractRoi::medAbstractRoi( dtkAbstractObject *parent )
    : dtkAbstractObject(parent)
    , d(new medAbstractRoiPrivate)
{
    d->isSelected = false;
}

medAbstractRoi::~medAbstractRoi( void )
{
    delete d;
    d = NULL;
}

unsigned int medAbstractRoi::getIdSlice() const
{
    return d->idSlice;
}

void medAbstractRoi::setIdSlice(unsigned int idSlice)
{
    d->idSlice=idSlice;
}

unsigned char medAbstractRoi::getOrientation()
{
    return d->orientation;
}

void medAbstractRoi::setOrientation(unsigned char orientation)
{
    d->orientation=orientation;
}

bool medAbstractRoi::isSelected()
{
    return d->isSelected;
}

void medAbstractRoi::select()
{
    d->isSelected = true;
    selected();
}

void medAbstractRoi::unselect()
{
    d->isSelected = false;
}

void medAbstractRoi::setRoiStatistics(RoiStatistics s)
{
    d->stats = s;
}
