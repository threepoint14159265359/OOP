#ifndef BOOK_H
#define BOOK_H

#include "Chapter.h"

using std::cout; using std::cin; using std::endl;

class Book{
public:
    Book(const std::string& title, const std::string& author, const std::string& genre, int rating){
        this->author = author; this->title = title; this->genre = genre; this->rating = rating;
    }
    void setChapter(const Chapter& chapter){ chapters.push_back(chapter); }//adding chapter to the chapters of current book
    
    //getters
    std::string getAuthor() const{return author;}
    std::string getTitle()const{return title;}
    std::string getGenre()const{return genre;}
    int getRating()const{return rating;}
    std::vector<Chapter> getChapters()const{ return chapters;}

private:
    std::string title; 
    std::string author;
    std::string genre;
    int rating;
    std::vector<Chapter> chapters; //Book has an association with chapters (Composition)
};




#endif // BOOK_H