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
    std::string imagePath;

public:
    AbstractMedia(
        const std::string & ="",
        const unsigned int & = 2025,
        const std::string & ="",
        const std::string & ="",
        const std::string& =":/Images/Src/Assets/default.png");

    virtual ~AbstractMedia() = 0;

    //Gets
    std::string getName() const;
    unsigned int getYear() const;
    std::string getAuthor() const;
    std::string getDescription() const;
    std::string getImage() const;
    //Sets
    void setName(const std::string &);
    void setYear(const unsigned int &);
    void setAuthor(const std::string &);
    void setDescription(const std::string &);
    void setImage(const std::string &);
    //Visitor
    virtual void accept(MediaVisitor *) const = 0;

};


#endif // ABSTRACTMEDIA_H
