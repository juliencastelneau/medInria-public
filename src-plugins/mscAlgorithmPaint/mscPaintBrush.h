#pragma once

#include "mscAlgorithmPaintPluginExport.h"

#include <itkImage.h>
#include <medAbstractRoi.h>

namespace msc
{

class mscPaintBrushPrivate;

typedef itk::Image <unsigned char, 2>              Mask2dType;

class MSCALGORITHMPAINT_EXPORT mscPaintBrush : public medAbstractRoi
{
    Q_OBJECT

public:
    mscPaintBrush(Mask2dType::Pointer slice, int id, bool isMaster, medAbstractRoi* parent = nullptr);

    virtual ~mscPaintBrush();

    void Off() override;

    void On() override;

    bool isVisible() override;

    void forceInvisibilityOn() override;

    void forceInvisibilityOff() override;

    QString info() override;

    QString type() override;

    void computeRoiStatistics() override;

    bool canRedo() override;

    bool canUndo() override;

    void undo() override;

    void redo() override;

    void saveState() override;

    bool copyROI(medAbstractView *view) override;

    medAbstractRoi *getCopy(medAbstractView *view) override;

    QList<medAbstractRoi *> *interpolate(medAbstractRoi *roi) override;

    Mask2dType::Pointer getSlice();

private:
    mscPaintBrushPrivate* d;
    virtual void setRightColor() override;

};
}


