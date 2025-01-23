#include "converter.h"
#include <QtCore/QtCore>

Converter::Converter() {}

QPixmap Converter::convertPathToPixmap(const std::string& path) {
    QString qPath = QString::fromStdString(path);
    QPixmap pixmap;

    if (!pixmap.load(qPath)) {
        qWarning("Failed to load pixmap from path: %s", qPath.toUtf8().constData());
    }

    return pixmap;
}

std::string Converter::convertPixmapToPath(const QPixmap& pixmap) {
    if (pixmap.isNull()) {
        return ":/Images/Src/Assets/default.png";
    }

    QDir tempDir("temp");
    if (!tempDir.exists()) {
        tempDir.mkpath(".");
    }

    QString tempFilePath = tempDir.filePath("image_" + QUuid::createUuid().toString() + ".png");
    if (!pixmap.save(tempFilePath, "PNG")) {
        throw std::runtime_error("Failed to save the QPixmap to the temporary file.");
    }
    QString relativePath = QDir::current().relativeFilePath(tempFilePath);

    return relativePath.toStdString();
}
