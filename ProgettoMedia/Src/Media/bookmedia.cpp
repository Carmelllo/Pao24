#include "bookmedia.h"

BookMedia::BookMedia(
    const std::string & n,
    const unsigned int & y,
    const std::string & a,
    const QPixmap& img,
    const unsigned int & pag,
    const std::string & publ,
    const std::string & g) : AbstractMedia(n,y,a,img), pages(pag), publisher(publ), genre(g) {}

BookMedia::~BookMedia() {}

unsigned int BookMedia::getPages() const{

    return pages;

}
std::string BookMedia::getPublisher() const{

    return publisher;

}
std::string BookMedia::getGenre() const{

    return genre;

}


void BookMedia::setPages(const unsigned int &pag){

    this->pages = pag;

}
void BookMedia::setPublisher(const std::string &publ){

    this->publisher = publ;

}
void BookMedia::setGenre(const std::string &g){

    this->genre = g;

}

void BookMedia::accept(MediaVisitor *visitor) const{

    visitor->visit(this);

}
