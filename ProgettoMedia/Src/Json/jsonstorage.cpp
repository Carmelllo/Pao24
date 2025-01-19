#include "jsonstorage.h"
#include "Src/Media/articlemedia.h"
#include "Src/Media/bookmedia.h"
#include "Src/Media/moviemedia.h"
#include "Src/Visitor/jsonvisitor.h"

JsonStorage::JsonStorage() {}

QJsonObject JsonStorage::turnToObject(const AbstractMedia & media){
    JsonVisitor* visitor = new JsonVisitor();
    media.accept(visitor);
    return visitor->getObject();
}

AbstractMedia* JsonStorage::turnToMedia(const QJsonObject & object){
    if (object.contains("Publisher")) {
        // It's a Book
        return new BookMedia(
            object.value("Name").toString().toStdString(),
            object.value("Year").toInt(),
            object.value("Author").toString().toStdString(),
            object.value("Description").toString().toStdString(),
            getImageFromJson(object),
            object.value("Pages").toInt(),
            object.value("Publisher").toString().toStdString(),
            object.value("Genre").toString().toStdString()
            );
    }
    else if (object.contains("Journal")) {
        // It's an Article
        return new ArticleMedia(
            object.value("Name").toString().toStdString(),
            object.value("Year").toInt(),
            object.value("Author").toString().toStdString(),
            object.value("Description").toString().toStdString(),
            getImageFromJson(object),
            object.value("Volume").toInt(),
            object.value("Issue").toInt(),
            object.value("Journal").toString().toStdString()
            );
    }

else if (object.contains("Director")) {
    // It's likely a Movie
    return new MovieMedia(
        object.value("Name").toString().toStdString(),
        object.value("Year").toInt(),
        object.value("Author").toString().toStdString(),
        object.value("Description").toString().toStdString(),
        getImageFromJson(object),
        object.value("Length").toInt(),
        object.value("Director").toString().toStdString(),
        object.value("Studio").toString().toStdString()
        );
}

throw std::invalid_argument("Unknown media type or missing required fields in JSON.");
}

QPixmap JsonStorage::getImageFromJson(const QJsonObject & object) {
    if (object.contains("Image")) {
        QString base64Image = object.value("Image").toString();
        QByteArray byteArray = QByteArray::fromBase64(base64Image.toLatin1());
        QPixmap image;
        if (image.loadFromData(byteArray)) {
            return image;
        } else {
            return QPixmap();
        }
    }
    return QPixmap();
}
