#include "Book.h"

using std::cout; 
using std::cin; 
using std::endl;
using std::string; 


void bookSimulation(const Book& book){
    cout << "Title\t\t\tAuthor\t\t\tGenre\t\t\tRating" << endl;
    cout << book.getTitle() << "\t" << book.getAuthor() << "\t" << book.getGenre() << "\t\t" << book.getRating() << endl;

    cout << "\n\n";
    std::vector<Chapter> chaps = book.getChapters();
    for(unsigned int i = 0; i < chaps.size(); i++){
        cout << chaps.at(i).getName() << "\tStart Page: " << chaps.at(i).getStartPage() << "\tEnd Page: " << chaps.at(i).getEndPage(); 
        cout << "\nPAGES in Chapter " << i << ":\n";
        std::vector<Page> pages = chaps.at(i).getPages(); 
        for(unsigned int j = 0; j<pages.size(); j++){
            cout << "\t\tPage: " << pages.at(j).getNumber() << "\tHeader: " << pages.at(j).getHeader() << "\n";
            cout << "\t\tContent: " << pages.at(j).getContent() << "\n";
            cout << "\t\tFooter: " << pages.at(j).getFooter() << "\n";
        }
    }
}



int main(){
    /*BOOK 1*/
    string title = "Wuthering Height";
    string author = "Emily Bronte";
    string genre = "Classic Romantic Novel";
    int rating = 4.7;
    Book book1(title, author, genre, rating);

    /*Chapter 1*/
    string name = "Chapter I";
    int startPage = 1, endPage = 5; 
    Chapter chapter1(name, startPage, endPage);
    /*Pages in Chapter 1*/
    int number = 1; 
    string footer = "1";
    string content = "Some content I don't know";
    Page page1(number, title, footer, content);
    chapter1.setPage(page1); //set page 1 of chapter 1
    number = 2; footer = "2";
    Page page2(number, title, footer, content);
    chapter1.setPage(page2); //set page 2 of chapter 1
    number = 3; footer = "3";
    Page page3(number, title, footer, content);
    chapter1.setPage(page3); //set page 3 of chapter 1
    number = 4; footer = "4";
    Page page4(number, title, footer, content);
    chapter1.setPage(page4); //set page 4 of chapter 1
    number = 5; footer = "5";
    Page page5(number, title, footer, content);
    chapter1.setPage(page5); //set page 5 of chapter 1
    book1.setChapter(chapter1);

    /**
     * Chapter II 
     */
    name = "Chapter II";
    startPage = 6;
    endPage = 9; 
    Chapter chapter2(name, startPage, endPage);
    /*Pages in Chapter 1*/
    number = 6; footer = "1";
    Page page6(number, title, footer, content);
    chapter2.setPage(page6); //set page 1 of chapter 1
    number = 7; footer = "7";
    Page page7(number, title, footer, content);
    chapter2.setPage(page7); //set page 2 of chapter 1
    number = 8; footer = "8";
    Page page8(number, title, footer, content);
    chapter2.setPage(page8); //set page 3 of chapter 1
    number = 9; footer = "9";
    Page page9(number, title, footer, content);
    chapter2.setPage(page9);
    book1.setChapter(chapter2);

    bookSimulation(book1);
}