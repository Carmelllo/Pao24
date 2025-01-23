#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include "Src/Container/container.h"
#include "Src/Visitor/concretevisitor.h"


class MediaManager {
private:

public:
    MediaManager();

    bool addMedia(Container* , AbstractMedia* );
    bool editMedia(Container* , const std::string& , ConcreteVisitor* );
    bool deleteMedia(Container* , const std::string& );
    const AbstractMedia* findMediaByName(const std::string& , Container* ) const;

};

#endif // MEDIAMANAGER_H
