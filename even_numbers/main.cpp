#include <iostream>
#include "fileenor.h"

/**
    @uthor: Hussain Izhar
    Task:   a: How many even numbers there are in a sequential input file containing integers?
            b: How many even numbers there are before the first negative number in the file?
            c: How many even numbers there are After the first negative number in the file?
            d: How many even numbers there are before and after the first negative number in the file? ||| We don't read the negative number itself
*/

using namespace std;


int evenCount(const std::string &file){
    fileEnor e(file);
    int count = 0;
    for(e.first(); !e.end(); e.next()){
        if(e.current() % 2 == 0){
            count++;
        }
    }
    return count;
}


int evenBeforeNegativeNumber(const std::string &file){
    fileEnor e(file);
    e.first();
    int cnt = 0;
    while(!e.end() && e.current() >= 0){
        if(e.current() % 2 == 0){
            ++cnt;
        }
        e.next();
    }
    return cnt;
}


int evenAfterNegativeNumber(const std::string &file){
    fileEnor e(file);
    e.first();
    int cnt = 0;
    while(!e.end() && e.current() >= 0){
        e.next();
    }
    e.next(); // must not count the negative number, coz we are searching for the numbers AFTER!
    while(!e.end()){
        if(e.current() % 2 == 0){
            ++cnt;
        }
        e.next();
    }
    return cnt;
}

int evenBeforeAndAfterNegativeNumber(const string &file){
    fileEnor e(file);
    int cnt = 0;
    while(!e.end() && e.current() >= 0){
        if(e.current() % 2 == 0){
            ++cnt;
        }
        e.next();
    }
    e.next();
    while(!e.end()){
        if(e.current() % 2 == 0){
            cnt++;
        }
        e.next();
    }
    return cnt;
}

int main(){
    int count;
    try{
        count = evenCount("1.txt");
        cout << "All: " << count << endl;
    }catch(fileEnor::errors e){
        cout << "File ERROR!" << endl;
    }

    try{
        count = evenBeforeNegativeNumber("1.txt");
        cout <<"Before: " << count << endl;
    }catch(fileEnor::errors e){
        cout << "File ERROR!" << endl;
    }

    try{
        count = evenAfterNegativeNumber("1.txt");
        cout << "After: " << count << endl;
    }catch(fileEnor::errors e){
        cout << "File ERROR!" << endl;
    }

    try{
        count = evenBeforeAndAfterNegativeNumber("1.txt");
        cout << "After: " << count << endl;
    }catch(fileEnor::errors e){
        cout << "File ERROR!" << endl;
    }

    return 0;
}
