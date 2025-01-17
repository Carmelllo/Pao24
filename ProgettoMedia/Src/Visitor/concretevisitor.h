#ifndef CONCRETEVISITOR_H
#define CONCRETEVISITOR_H

#include "mediavisitor.h"
#include <QPixmap>

class ConcreteVisitor : public MediaVisitor
{
private:
    QPixmap icon;
public:
    ConcreteVisitor();
    virtual ~ConcreteVisitor();

    virtual void visit(const ArticleMedia *) override;
    virtual void visit(const BookMedia *) override;
    virtual void visit(const MovieMedia *) override;
    void setIcon(const ArticleMedia *);
    void setIcon(const BookMedia *);
    void setIcon(const MovieMedia *);
    QPixmap getIcon() const;

};

#endif // CONCRETEVISITOR_H
