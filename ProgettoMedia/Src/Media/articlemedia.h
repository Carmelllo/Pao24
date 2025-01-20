#ifndef ARTICLEMEDIA_H
#define ARTICLEMEDIA_H
#include "abstractmedia.h"

class ArticleMedia : public AbstractMedia
{
private:
    unsigned int volume;
    unsigned int issue;
    std::string journal;
public:
    ArticleMedia(
        const std::string & ="",
        const unsigned int & = 2025,
        const std::string & ="",
        const std::string & ="",
        const std::string& =":/Images/Src/Assets/default.png",
        const unsigned int  & =0,
        const unsigned int  & =0,
        const std::string & ="");

    virtual ~ArticleMedia() override;

    //Gets
    unsigned int getVolume() const;
    unsigned int getIssue() const;
    std::string getJournal() const;
    //Sets
    void setVolume(const unsigned int &);
    void setIssue(const unsigned int &);
    void setJournal(const std::string &);
    //Visitor
    void accept(MediaVisitor *) const override;
};

#endif // ARTICLEMEDIA_H
