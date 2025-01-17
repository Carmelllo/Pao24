#ifndef CONCRETEVISITOR_H
#define CONCRETEVISITOR_H

#include "mediavisitor.h"

class ConcreteVisitor : public MediaVisitor
{
private:
public:
    ConcreteVisitor();
    virtual ~ConcreteVisitor();

    virtual void visit(const ArticleMedia *) override;
    virtual void visit(const BookMedia *) override;
    virtual void visit(const MovieMedia *) override;
    void setIcon(const ArticleMedia *);
    void setIcon(const BookMedia *);
    void setIcon(const MovieMedia *);

};

#endif // CONCRETEVISITOR_H
