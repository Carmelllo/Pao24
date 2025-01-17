#ifndef MOVIEMEDIA_H
#define MOVIEMEDIA_H
#include "abstractmedia.h"

class MovieMedia : public AbstractMedia
{
private:
    double length;
    std::string director;
    std::string studio;

public:
    MovieMedia(
        const std::string & ="",
        const unsigned int & = 2025,
        const std::string & ="",
        const std::string & ="",
        const QPixmap& = QPixmap(":/Images/default.png"),
        const double& = 0,
        const std::string& = "",
        const std::string& ="");

    virtual ~MovieMedia() override;

    //Gets
    double getLength() const;
    std::string getDirector() const;
    std::string getStudio() const;
    //Sets
    void setLength(const double&);
    void setDirector(const std::string &);
    void setStudio(const std::string &);
    //Visitor
    void accept(MediaVisitor *) const override;

};

#endif // MOVIEMEDIA_H
