#ifndef JSONSTORAGE_H
#define JSONSTORAGE_H

#include "Src/Media/abstractmedia.h"

class JsonStorage
{
public:
    JsonStorage();
    QJsonObject turnToObject(const AbstractMedia &);
    static AbstractMedia* turnToMedia(const QJsonObject &);
    static QPixmap getImageFromJson(const QJsonObject &);

};

#endif // JSONSTORAGE_H
