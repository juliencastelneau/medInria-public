#include "computerInfo.h"
#include <QDebug>
#include <QSystemTrayIcon>

namespace medComputerInfo
{
    void startNotifier(QTimer &timer)
    {
        QObject::connect(&timer, &QTimer::timeout, [&]() {
            // QSystemTrayIcon tray;
            // tray.setIcon(QIcon(":/medInria.ico"));
            // tray.setContextMenu(menu);
            long long totalRam;
            long long usageRam;
            double loadavg;
            medComputerInfo::ramInfo(totalRam, usageRam);
            // medComputerInfo::getLoadAvg(&loadavg);
            // tray.show();
            // qDebug() << " total " << totalRam;
            // qDebug() << " usage " << usageRam;
            // qDebug() << " cpu " << loadavg;

            int p = 1024 * 1024 * 1024;
            int totalRamG = totalRam / p;
            int usageRamG = usageRam / p;
            qDebug() << " t " << totalRamG;
            qDebug() << " u " << usageRamG;
            // QString str = QString("total : %1 /===/ usage : %2").arg(totalRam).arg(usageRam);
            // QString percent = QString("load %1").arg(loadavg);
            // tray.showMessage(str, str);
            // tray.showMessage("percentage: ", percent);
            timer.setInterval(10000);
        });
        timer.start(10000);
    }
}
