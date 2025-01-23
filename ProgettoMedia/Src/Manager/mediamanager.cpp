#include "mediamanager.h"
#include "Src/Media/abstractmedia.h"

MediaManager::MediaManager() {}

bool MediaManager::addMedia(Container* container, AbstractMedia* media) {
    for (auto it = container->begin(); it != container->end(); ++it) {
        if (media->getName() == (*it)->getName()) {
            return false;
        }
    }
    container->add(media);
    return true;
}

bool MediaManager::editMedia(Container* container, const std::string& name, ConcreteVisitor* visitor) {
    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((*it)->getName() == name) {
            (*it)->accept(visitor);
            container->remove(*it);
            return true;
        }
    }
    return false;
}

bool MediaManager::deleteMedia(Container* container, const std::string& name) {
    for (auto it = container->begin(); it != container->end();) {
        if ((*it)->getName() == name) {
            container->remove(*it);
            return true;
        }
        ++it;
    }
    return false;
}

const AbstractMedia* MediaManager::findMediaByName(const std::string& name, Container* container) const{
    for (auto it = container->begin(); it != container->end(); ++it) {
        if (name == (*it)->getName()) {
            return *it;
        }
    }
    return nullptr;
}


