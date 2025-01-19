#ifndef MOVIEMEDIA_H
#define MOVIEMEDIA_H
#include "abstractmedia.h"

class MovieMedia : public AbstractMedia
{
private:
    unsigned int length;
    std::string director;
    std::string studio;

public:
    MovieMedia(
        const std::string & ="",
        const unsigned int & = 2025,
        const std::string & ="",
        const std::string & ="",
        const QPixmap& = QPixmap(":/Images/Src/Assets/default.png"),
        const unsigned int& = 0,
        const std::string& = "",
        const std::string& ="");

    virtual ~MovieMedia() override;

    //Gets
    unsigned int getLength() const;
    std::string getDirector() const;
    std::string getStudio() const;
    //Sets
    void setLength(const unsigned int&);
    void setDirector(const std::string &);
    void setStudio(const std::string &);
    //Visitor
    void accept(MediaVisitor *) const override;

};

#endif // MOVIEMEDIA_H
