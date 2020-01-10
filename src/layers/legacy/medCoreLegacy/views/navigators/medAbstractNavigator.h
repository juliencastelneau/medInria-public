/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2018. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <dtkCoreSupport/dtkAbstractViewNavigator.h>

#include<medAbstractParameterL.h>
#include <medImageViewEnum.h>

#include <medCoreLegacyExport.h>

#include <QtXml/QDomDocument>

class medAbstractView;
class medBoolParameterL;


class medAbstractNavigatorPrivate;
class MEDCORELEGACY_EXPORT medAbstractNavigator : public dtkAbstractViewNavigator
{
    Q_OBJECT

public:
             medAbstractNavigator(medAbstractView* parent);
    virtual ~medAbstractNavigator();

public:
    virtual QString description() const = 0;
    virtual QString name() const;
    virtual QString version() const;

    QWidget* toolBoxWidget();
    QWidget* toolBarWidget();

    virtual QList<medAbstractParameterL*> linkableParameters() = 0;
    virtual QList<medBoolParameterL*> mouseInteractionParameters() = 0;

    virtual void toXMLNode(QDomDocument* doc,QDomElement* currentNode);

protected:
    virtual QWidget* buildToolBoxWidget() = 0;
    virtual QWidget* buildToolBarWidget() = 0;

private slots:


private:
    medAbstractNavigatorPrivate *d;

/*=========================================================================
                        NOT IMPLEMENTED HERE ON PURPOSE
*=========================================================================*/
public slots:
    virtual void updateWidgets();

private:
    using dtkAbstractViewNavigator::setView;
    using dtkAbstractViewNavigator::view;

    using dtkAbstractViewNavigator::setData;
    using dtkAbstractViewNavigator::data;
    using dtkAbstractViewNavigator::output;
    using dtkAbstractViewNavigator::predraw;
    using dtkAbstractViewNavigator::draw;
    using dtkAbstractViewNavigator::postdraw;
    using dtkAbstractViewNavigator::enabled;
    using dtkAbstractViewNavigator::enable;
    using dtkAbstractViewNavigator::disable;

};
