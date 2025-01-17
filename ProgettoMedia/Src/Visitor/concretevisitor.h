#ifndef CONCRETEVISITOR_H
#define CONCRETEVISITOR_H

#include "mediavisitor.h"
#include <QPixmap>

class ConcreteVisitor : public MediaVisitor
{
public:
    struct Attributes {
        std::string name;
        std::string year;
        std::string author;
        QPixmap img;
        std::unordered_map<std::string, std::string> details;
    };
private:
    QPixmap icon;
    Attributes attributes;
public:


    ConcreteVisitor();
    virtual ~ConcreteVisitor();

    virtual void visit(const ArticleMedia *) override;
    virtual void visit(const BookMedia *) override;
    virtual void visit(const MovieMedia *) override;
    void setIcon(const ArticleMedia *);
    void setIcon(const BookMedia *);
    void setIcon(const MovieMedia *);
    void setAttributes(const ArticleMedia *);
    void setAttributes(const BookMedia *);
    void setAttributes(const MovieMedia *);

    QPixmap getIcon() const;
    Attributes getAttributes() const;

};

#endif // CONCRETEVISITOR_H
