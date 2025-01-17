#include "concretevisitor.h"
#include "Src/Media/articlemedia.h"
#include "Src/Media/bookmedia.h"
#include "Src/Media/moviemedia.h"

ConcreteVisitor::ConcreteVisitor() {}

ConcreteVisitor::~ConcreteVisitor() {}

void ConcreteVisitor::visit(const ArticleMedia * media){
    setIcon(media);
    setAttributes(media);

}
void ConcreteVisitor::visit(const BookMedia * media){
    setIcon(media);
    setAttributes(media);

}
void ConcreteVisitor::visit(const MovieMedia * media){
    setIcon(media);
    setAttributes(media);

}

void  ConcreteVisitor::setIcon(const ArticleMedia *){
    icon.load(":/Images/Article.png");

}
void  ConcreteVisitor::setIcon(const BookMedia *){
    icon.load(":/Images/Book.png");

}
void  ConcreteVisitor::setIcon(const MovieMedia *){
    icon.load(":/Images/Movie.png");
}

QPixmap ConcreteVisitor::getIcon() const{
    return icon;
}

ConcreteVisitor::Attributes ConcreteVisitor::getAttributes() const{
    return attributes;
}

void ConcreteVisitor::setAttributes(const ArticleMedia * media){
    attributes.name = media->getName() ;
    attributes.year = std::to_string( media->getYear() );
    attributes.author = media->getAuthor() ;
    attributes.img = media->getImage();
    attributes.details["Issue"] = std::to_string(media->getIssue());
    attributes.details["Volume"] = std::to_string(media->getVolume());
    attributes.details["Journa"] = media->getJournal();
}
void ConcreteVisitor::setAttributes(const BookMedia * media){
    attributes.name = media->getName() ;
    attributes.year = std::to_string( media->getYear() );
    attributes.author = media->getAuthor() ;
    attributes.img = media->getImage();
    attributes.details["Pages"] = std::to_string(media->getPages());
    attributes.details["Publisher"] = media->getPublisher();
    attributes.details["Genre"] = media->getGenre();
}
void ConcreteVisitor::setAttributes(const MovieMedia * media){
    attributes.name = media->getName() ;
    attributes.year = std::to_string( media->getYear() );
    attributes.author = media->getAuthor() ;
    attributes.img = media->getImage();
    attributes.details["Length"] = (std::to_string(media->getLength()) + " minutes");
    attributes.details["Director"] = media->getDirector();
    attributes.details["Studio"] = media->getStudio();
}





