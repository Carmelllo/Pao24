#ifndef CONVERTER_H
#define CONVERTER_H
#include <QPixmap>
#include <QString>
#include <string>


class Converter
{
public:
    Converter();
   static QPixmap convertPathToPixmap(const std::string& );
   static std::string convertPixmapToPath(const QPixmap& );
};

#endif // CONVERTER_H
