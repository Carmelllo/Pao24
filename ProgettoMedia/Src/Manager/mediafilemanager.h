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
    static void saveMedia(const QString& , Container* );
    static void clearMedia(Container* );
    static bool openMedia(const QString& , Container* );
};


#endif // MEDIAFILEMANAGER_H
