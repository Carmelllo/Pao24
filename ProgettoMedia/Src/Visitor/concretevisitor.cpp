#include "concretevisitor.h"


ConcreteVisitor::ConcreteVisitor() {}

ConcreteVisitor::~ConcreteVisitor() {}

void ConcreteVisitor::visit(const ArticleMedia * media){
    setIcon(media);
}
void ConcreteVisitor::visit(const BookMedia * media){
    setIcon(media);

}
void ConcreteVisitor::visit(const MovieMedia * media){
    setIcon(media);

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





