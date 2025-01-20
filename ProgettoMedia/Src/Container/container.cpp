#include "container.h"
#include "Src/Media/abstractmedia.h"


//DELETE
void Container::remove(const AbstractMedia* m) {
    bool found = false;
    for (auto it = media.begin(); it != media.end() && found == false; it++)
    {
        if (m->getName() == (*it)->getName())
        {
            media.erase(it);
            found=true;
        }
    }
}
//UPDATE
/*void Container::modify(AbstractMedia * m,std::string & n, unsigned int & y,std::string & a) {
    for(auto it = media.begin(); it!=media.end(); ++it){
        if(m->getName() == (*it)->getName())
        {
            (*it)->setName(n);
            (*it)->setYear(y);
            (*it)->setName(a);
        }
    }
}*/
//CREATE
void Container::add(const AbstractMedia* m){
    media.push_back(m);

}

//READs by name
const AbstractMedia* Container::getMedia(std::string & n) const{
    for(auto it = media.begin(); it!=media.end(); ++it){
        if(n == (*it)->getName())
        {
            return *it;
        }
    }
    return nullptr;
}
Container::~Container(){
for (auto mediaItem : media) {
    delete mediaItem; // Delete each object pointed to by the pointer
}
}


std::vector<const AbstractMedia*> Container::getMediaVec() const{
    return media;
}


std::vector<const AbstractMedia*>::const_iterator Container::begin() const{
    return media.begin();
}

std::vector<const AbstractMedia*>::const_iterator Container::end() const{
    return media.end();
}

void Container::search(Container* container, std::string query){

    for(auto it = media.begin(); it!=media.end(); ++it)
    {
        if((*it)->getName().find(query) != std::string::npos){
            container->add(*it);
        }
    }
}

bool Container::empty(){
    return media.empty();
}

void Container::clear(){
    media.clear();
}

int Container::size()
{
    return media.size();
}
