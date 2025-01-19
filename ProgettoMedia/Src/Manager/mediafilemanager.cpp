// MediaFileManager.cpp
#include "mediafilemanager.h"
#include <QtCore/qjsonobject.h>
#include "Src/Json/jsonstorage.h"


void MediaFileManager::saveMedia(const QString& fileName, Container* container) {
    JsonStorage jsonStorage;
    QJsonArray mediaArray;
    for (auto it = container->begin(); it != container->end(); ++it) {
        mediaArray.append(jsonStorage.turnToObject(**it));  // Add each media to the JSON array
    }
    QJsonDocument doc(mediaArray);
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Could not open the file for writing."));
        return;
    }
    saveFile.write(doc.toJson());
    saveFile.close();

    QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Your media has been saved!"));
}

bool MediaFileManager::openMedia(const QString& fileName, Container* container) {
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Could not open the file for reading."));
        return false;
    }
    QByteArray fileData = loadFile.readAll();
    loadFile.close();
    QJsonDocument doc = QJsonDocument::fromJson(fileData);
    if (doc.isNull()) {
        QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Invalid JSON data."));
        return false;
    }
    QJsonArray mediaArray = doc.array();

    container->clear();  // Clear existing media

    for (const QJsonValue &value : mediaArray) {
        if (value.isObject()) {
            QJsonObject mediaObject = value.toObject();

            try {
                AbstractMedia* media = JsonStorage::turnToMedia(mediaObject);
                container->add(media);
            } catch (const std::invalid_argument &e) {
                QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Error processing JSON: ") + e.what());
                return false;
            }
        }
    }

    QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Media has been loaded successfully!"));
    return true;
}
