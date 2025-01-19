#ifndef MEDIAFILEMANAGER_H
#define MEDIAFILEMANAGER_H

#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
#include "Src/Container/container.h"

class MediaFileManager {
public:
    static void saveMedia(const QString& fileName, Container* container);
    static bool openMedia(const QString& fileName, Container* container);
};


#endif // MEDIAFILEMANAGER_H
