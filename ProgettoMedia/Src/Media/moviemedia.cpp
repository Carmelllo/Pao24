#include "moviemedia.h"

MovieMedia::MovieMedia(
    const std::string & n,
    const unsigned int & y,
    const std::string & a,
    const std::string & d,
    const QPixmap& img,
    const unsigned int&l,
    const std::string&dir,
    const std::string&s) : AbstractMedia(n,y,a,d,img), length(l), director(dir), studio(s) {}

MovieMedia::~MovieMedia() {}

unsigned int MovieMedia::getLength() const{
    return length;

}

std::string MovieMedia::getDirector() const{

    return director;

}

std::string MovieMedia::getStudio() const{

    return studio;

}

void MovieMedia::setLength(const unsigned int &l){

    this->length = l;

}

void MovieMedia::setDirector(const std::string &d){

    this->director = d;

}

void MovieMedia::setStudio(const std::string &s){

    this->studio = s;

}

void MovieMedia::accept(MediaVisitor *visitor) const{

    visitor->visit(this);

}


