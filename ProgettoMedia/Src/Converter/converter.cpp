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
        return ":/Images/Src/Assets/default.png";  // Return default image path if pixmap is empty
    }

    // Create the temp folder in the project directory if it doesn't exist
    QDir tempDir("temp"); // "temp" folder in the current directory (project folder)
    if (!tempDir.exists()) {
        tempDir.mkpath("."); // Create the folder if it doesn't exist
    }

    // Generate a unique filename for the temporary image file
    QString tempFilePath = tempDir.filePath("image_" + QUuid::createUuid().toString() + ".png");

    // Save the pixmap to the file in the temp folder
    if (!pixmap.save(tempFilePath, "PNG")) {
        throw std::runtime_error("Failed to save the QPixmap to the temporary file.");
    }

    // Convert the absolute path to a relative path
    QString relativePath = QDir::current().relativeFilePath(tempFilePath);

    return relativePath.toStdString();  // Return the relative path of the saved file
}
