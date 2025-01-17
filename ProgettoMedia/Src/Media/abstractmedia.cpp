#include "abstractmedia.h"

AbstractMedia::AbstractMedia(
    const std::string &n,
    const unsigned int &y,
    const std::string &a,
    const QPixmap& img) : name(n) , year(y) , author(a) , image(img){};


AbstractMedia::~AbstractMedia(){}



std::string AbstractMedia::getName() const{

    return name;

}

unsigned int AbstractMedia::getYear() const{

    return year;

}

std::string AbstractMedia::getAuthor() const{

    return author;

}

QPixmap AbstractMedia::getImage() const{
    return image;
}


void AbstractMedia::setName(const std::string &n){

    this->name = n;

}

void AbstractMedia::setYear(const int &y){

    this->year = y;

}

void AbstractMedia::setAuthor(const std::string &a){

    this->author = a;

}
