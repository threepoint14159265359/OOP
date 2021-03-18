#include "fileenor.h"
#include <iostream>

/*
    @uthor: Hussain Izhar
    Task: Object Oriented Programming, Spring 2021, ELTE
*/



void ReadData(const string &file){
    fileEnor e(file);
    for(e.first(); !e.end(); e.next()){
        cout <<  " ("  << e.current().rNum  << ", "  << e.current().rNum_frequency << ") " << endl;
    }
}

int main()
{
    ReadData("test.txt");
    return 0;
}
