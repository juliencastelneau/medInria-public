#pragma once

#include "mscAlgorithmPaintPluginExport.h"

#include <medAbstractRoi.h>

namespace msc
{

class MSCALGORITHMPAINT_EXPORT mscPaintBrush : public medAbstractRoi
{
    Q_OBJECT

public:
    mscPaintBrush(medAbstractRoi* parent = nullptr);

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

};
}


