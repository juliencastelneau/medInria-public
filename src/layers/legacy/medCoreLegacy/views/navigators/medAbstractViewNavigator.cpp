/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2020. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medAbstractView.h>
#include <medAbstractViewNavigator.h>
#include <medDoubleParameterL.h>
#include <medVector2DParameterL.h>

class medAbstractViewNavigatorPrivate
{
public:
    medAbstractView *view;
    medDoubleParameterL *zoomParameter;
    medVector2DParameterL *panParameter;   
};

medAbstractViewNavigator::medAbstractViewNavigator(medAbstractView* parent):
    medAbstractNavigator(parent), d(new medAbstractViewNavigatorPrivate)
{
    d->view = parent;
    d->zoomParameter = nullptr;
    d->panParameter = nullptr;
}

medAbstractViewNavigator::~medAbstractViewNavigator()
{
    delete d;
}

medDoubleParameterL* medAbstractViewNavigator::zoomParameter()
{
    if(!d->zoomParameter)
    {
        d->zoomParameter = new medDoubleParameterL("Zoom", this);
        d->zoomParameter->setValue(1);
        connect(d->zoomParameter, SIGNAL(valueChanged(double)), this, SLOT(setZoom(double)));
    }
    return d->zoomParameter;
}

medAbstractVector2DParameterL* medAbstractViewNavigator::panParameter()
{
    if(!d->panParameter)
    {
        d->panParameter = new medVector2DParameterL("Pan", this);
        connect(d->panParameter, SIGNAL(valueChanged(QVector2D)), this, SLOT(setPan(QVector2D)));
    }
    return d->panParameter;
}
