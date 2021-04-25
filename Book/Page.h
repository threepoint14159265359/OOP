#ifndef PAGE_H
#define PAGE_H


#include <iostream>
#include <string>
#include <vector>
class Page
{    
public:
    Page(unsigned int number, const std::string& header, const std::string& footer,const std::string& content){
        this->number = number;
        this->header = header; 
        this->footer = footer;
        this->content = content;
    }
    //getters
    int getNumber(){return number;}
    std::string getHeader(){return header; }
    std::string getFooter(){return footer; }
    std::string getContent(){return content;}
private:
    int number;
    std::string header, footer, content; 
}; //stand alone class 





#endif // PAGE_H