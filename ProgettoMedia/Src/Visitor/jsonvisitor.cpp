#include "jsonvisitor.h"
#include "Src/Media/articlemedia.h"
#include "Src/Media/bookmedia.h"
#include "Src/Media/moviemedia.h"
#include <QtCore/qbuffer.h>

JsonVisitor::JsonVisitor() {}


void JsonVisitor::visit(const ArticleMedia * media){
    QJsonObject article;
    article.insert("Name", QString::fromStdString(media->getName()));
    article.insert("Year", QJsonValue::fromVariant(media->getYear()));
    article.insert("Author", QString::fromStdString(media->getAuthor()));
    article.insert("Description", QString::fromStdString(media->getDescription()));
    article.insert("Volume", QJsonValue::fromVariant(media->getVolume()));
    article.insert("Issue", QJsonValue::fromVariant(media->getIssue()));
    article.insert("Journal", QString::fromStdString(media->getJournal()));
    article.insert("Image",QString::fromStdString(media->getImage()));
    // if (!image.isNull()) {
    //     QByteArray byteArray;
    //     QBuffer buffer(&byteArray);
    //     buffer.open(QIODevice::WriteOnly);
    //     image.save(&buffer, "PNG");
    //     QString base64Image = QString::fromLatin1(byteArray.toBase64());
    //     article.insert("Image", QJsonValue(base64Image));
    // }

    object = article;

}

void JsonVisitor::visit(const BookMedia * media){
    QJsonObject book;
    book.insert("Name", QString::fromStdString(media->getName()));
    book.insert("Year", QJsonValue::fromVariant(media->getYear()));
    book.insert("Author", QString::fromStdString(media->getAuthor()));
    book.insert("Description", QString::fromStdString(media->getDescription()));
    book.insert("Pages", QJsonValue::fromVariant(media->getPages()));
    book.insert("Publisher", QString::fromStdString(media->getPublisher()));
    book.insert("Genre", QString::fromStdString(media->getGenre()));
    book.insert("Image",QString::fromStdString(media->getImage()));

    // if (!image.isNull()) {
    //     QByteArray byteArray;
    //     QBuffer buffer(&byteArray);
    //     buffer.open(QIODevice::WriteOnly);
    //     image.save(&buffer, "PNG");
    //     QString base64Image = QString::fromLatin1(byteArray.toBase64());
    //     book.insert("Image", QJsonValue(base64Image));
    // }

    object = book;


}
void JsonVisitor::visit(const MovieMedia * media){
    QJsonObject movie;
    movie.insert("Name", QString::fromStdString(media->getName()));
    movie.insert("Year", QJsonValue::fromVariant(media->getYear()));
    movie.insert("Author", QString::fromStdString(media->getAuthor()));
    movie.insert("Description", QString::fromStdString(media->getDescription()));
    movie.insert("Length", QJsonValue::fromVariant(media->getLength()));
    movie.insert("Director", QString::fromStdString(media->getDirector()));
    movie.insert("Studio", QString::fromStdString(media->getStudio()));
    movie.insert("Image",QString::fromStdString(media->getImage()));
    // if (!image.isNull()) {
    //     QByteArray byteArray;
    //     QBuffer buffer(&byteArray);
    //     buffer.open(QIODevice::WriteOnly);
    //     image.save(&buffer, "PNG");
    //     QString base64Image = QString::fromLatin1(byteArray.toBase64());
    //     movie.insert("Image", QJsonValue(base64Image));
    // }

    object = movie;

}

QJsonObject JsonVisitor::getObject() const{
    return object;
}
