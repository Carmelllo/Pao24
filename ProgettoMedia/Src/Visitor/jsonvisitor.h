#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>
#include "Src/Visitor/mediavisitor.h"

class JsonVisitor : public MediaVisitor
{
private:
    QJsonObject object;
public:
    JsonVisitor();

     virtual void visit(const ArticleMedia *) override;
     virtual void visit(const BookMedia *) override ;
     virtual void visit(const MovieMedia *) override;

    QJsonObject getObject() const;
};

#endif // JSONVISITOR_H
