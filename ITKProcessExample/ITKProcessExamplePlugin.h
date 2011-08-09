// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#ifndef ITKPROCESSEXAMPLEPLUGIN_H
#define ITKPROCESSEXAMPLEPLUGIN_H

#include <dtkCore/dtkPlugin.h>

#include "ITKProcessExamplePluginExport.h"

class ITKPROCESSEXAMPLEPLUGIN_EXPORT ITKProcessExamplePluginPrivate;

class ITKPROCESSEXAMPLEPLUGIN_EXPORT ITKProcessExamplePlugin : public dtkPlugin
{
    Q_OBJECT
    Q_INTERFACES(dtkPlugin)

public:
     ITKProcessExamplePlugin(QObject *parent = 0);
    ~ITKProcessExamplePlugin(void);

    virtual bool initialize(void);
    virtual bool uninitialize(void);

    virtual QString name(void) const;
    virtual QString description(void) const;

    virtual QStringList tags(void) const;
    virtual QStringList types(void) const;

private:
     ITKProcessExamplePluginPrivate *d;
};

#endif
