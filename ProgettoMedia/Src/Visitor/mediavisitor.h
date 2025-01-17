#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H


class BookMedia;
class ArticleMedia;
class MovieMedia;


class MediaVisitor
{
public:
    MediaVisitor();
    virtual ~MediaVisitor();

    virtual void visit(const ArticleMedia *) = 0;
    virtual void visit(const BookMedia *) = 0;
    virtual void visit(const MovieMedia *) = 0;
};

#endif // MEDIAVISITOR_H
