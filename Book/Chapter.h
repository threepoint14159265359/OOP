#ifndef CHAPTER_H
#define CHAPTER_H
#include "Page.h"


class Chapter
{
public:
    Chapter(std::string name, int pageStart, int pageEnd){
        this->name = name; this->pageStart = pageStart; this->pageEnd = pageEnd;
    }
    void setPage(const Page& page){pages.push_back(page);} // setting a page in the current chapter
    std::vector<Page> getPages(){return pages;}
    
    //getters
    std::string getName(){return name; }
    int getStartPage(){return pageStart;}
    int getEndPage(){return pageEnd;}

private:
    std::string name;
    int pageStart, pageEnd; 
    std::vector<Page> pages; //Chapter has an association with Page (Composition)
};


#endif // CHAPTER_H
