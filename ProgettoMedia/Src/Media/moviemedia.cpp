#include "moviemedia.h"

MovieMedia::MovieMedia(
    const std::string & n,
    const unsigned int & y,
    const std::string & a,
    const QPixmap& img,
    const double&l,
    const std::string&d,
    const std::string&s) : AbstractMedia(n,y,a,img), length(l), director(d), studio(s) {}

MovieMedia::~MovieMedia() {}

double MovieMedia::getLength() const{

    return length;

}

std::string MovieMedia::getDirector() const{

    return director;

}

std::string MovieMedia::getStudio() const{

    return studio;

}

void MovieMedia::setLength(const double &l){

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


