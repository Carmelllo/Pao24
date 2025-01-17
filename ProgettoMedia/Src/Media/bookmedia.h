#ifndef BOOKMEDIA_H
#define BOOKMEDIA_H
#include "abstractmedia.h"

class BookMedia : public AbstractMedia
{
private:
    unsigned int pages;
    std::string publisher;
    std::string genre;

public:
    BookMedia(
        const std::string & ="",
        const unsigned int & = 2025,
        const std::string & ="",
        const std::string & ="",
        const QPixmap& = QPixmap(":/Images/default.png"),
        const unsigned int & = 0,
        const std::string & ="",
        const std::string & ="");

    virtual ~BookMedia() override;

    //Gets
    unsigned int getPages() const;
    std::string getPublisher() const;
    std::string getGenre() const;
    //Sets
    void setPages(const unsigned int &);
    void setPublisher(const std::string &);
    void setGenre(const std::string &);
    //Visitor
    void accept(MediaVisitor *) const override;
};

#endif // BOOKMEDIA_H
