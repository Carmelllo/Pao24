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
        // Libro
        return new BookMedia(
            object.value("Name").toString().toStdString(),
            object.value("Year").toInt(),
            object.value("Author").toString().toStdString(),
            object.value("Description").toString().toStdString(),
            object.value("Image").toString().toStdString(),
            object.value("Pages").toInt(),
            object.value("Publisher").toString().toStdString(),
            object.value("Genre").toString().toStdString()
            );
    }
    else if (object.contains("Journal")) {
        // Articolo
        return new ArticleMedia(
            object.value("Name").toString().toStdString(),
            object.value("Year").toInt(),
            object.value("Author").toString().toStdString(),
            object.value("Description").toString().toStdString(),
            object.value("Image").toString().toStdString(),
            object.value("Volume").toInt(),
            object.value("Issue").toInt(),
            object.value("Journal").toString().toStdString()
            );
    }

else if (object.contains("Director")) {
    // Film
    return new MovieMedia(
        object.value("Name").toString().toStdString(),
        object.value("Year").toInt(),
        object.value("Author").toString().toStdString(),
        object.value("Description").toString().toStdString(),
        object.value("Image").toString().toStdString(),
        object.value("Length").toInt(),
        object.value("Director").toString().toStdString(),
        object.value("Studio").toString().toStdString()
        );
}

throw std::invalid_argument("Unknown media type or missing required fields in JSON.");
}

