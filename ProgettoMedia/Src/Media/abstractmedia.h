#ifndef ABSTRACTMEDIA_H
#define ABSTRACTMEDIA_H


#include<string>
#include<QLabel>
#include "../Visitor/mediavisitor.h"


class MediaVisitor;

class AbstractMedia
{
private:
    std::string name;
    unsigned int year;
    std::string author;
    std::string description;
    QPixmap image;

public:
    AbstractMedia(
        const std::string & ="",
        const unsigned int & = 2025,
        const std::string & ="",
        const std::string & ="",
        const QPixmap& = QPixmap(":/Images/Src/Assets/default.png"));

    virtual ~AbstractMedia() = 0;

    //Gets
    std::string getName() const;
    unsigned int getYear() const;
    std::string getAuthor() const;
    std::string getDescription() const;
    QPixmap getImage() const;
    //Sets
    void setName(const std::string &);
    void setYear(const int &);
    void setAuthor(const std::string &);
    //Visitor
    virtual void accept(MediaVisitor *) const = 0;

};


#endif // ABSTRACTMEDIA_H
