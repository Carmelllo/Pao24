#include "articlemedia.h"

ArticleMedia::ArticleMedia(
    const std::string & n,
    const unsigned int & y,
    const std::string & a,
    const std::string & d,
    const QPixmap& img,
    const unsigned int & v,
    const unsigned int & i,
    const std::string & j) : AbstractMedia(n,y,a,d,img),volume(v) , issue(i) , journal(j) {}

ArticleMedia::~ArticleMedia() {}


unsigned int ArticleMedia::getVolume() const{

    return volume;

}
unsigned int ArticleMedia::getIssue() const{

    return issue;

}
std::string ArticleMedia::getJournal() const{

    return journal;

}
//Sets
void ArticleMedia::setVolume(const unsigned int &v){

    this->volume = v;

}
void ArticleMedia::setIssue(const unsigned int &i){

    this->issue = i;

}
void ArticleMedia::setJournal(const std::string &j){

    this->journal =j;

}

void ArticleMedia::accept(MediaVisitor *visitor) const{

    visitor->visit(this);

}
