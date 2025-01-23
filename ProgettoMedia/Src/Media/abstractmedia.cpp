#include "abstractmedia.h"

AbstractMedia::AbstractMedia(
    const std::string &n,
    const unsigned int &y,
    const std::string &a,
    const std::string &d,
    const std::string &img) : name(n) , year(y) , author(a) , description(d), imagePath(img){

};


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

std::string AbstractMedia::getImage() const{
    return imagePath;
}

std::string AbstractMedia::getDescription() const{
    return description;
}


void AbstractMedia::setName(const std::string &n){

    this->name = n;

}

void AbstractMedia::setYear(const unsigned int &y){

    this->year = y;

}

void AbstractMedia::setAuthor(const std::string &a){

    this->author = a;

}

void AbstractMedia::setDescription(const std::string &d){

    this->description = d;

}
void AbstractMedia::setImage(const std::string &i){

    this->imagePath = i;
}
