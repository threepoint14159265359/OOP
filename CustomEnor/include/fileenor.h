#ifndef FILEENOR_H
#define FILEENOR_H
#include <fstream>
using namespace std;
/**
    FILE FORMAT:
    It must receive a file that is sorted in ascending order.
    The file must contain only integer numbers.
    If other than that, the program won't produce what is expected.

    EXAMPLE: filename = 1.txt
    1 1 1 2 100 102 102 102 1000
*/



struct DataType{
    int rNum, rNum_frequency; //retrieved number from the file and its frequency
};



enum Status{norm, abnorm};

class fileEnor
{
    public:
        enum errors{corrupt_file}; ///exceptions
        fileEnor(const string &filename); ///constructor
        void first(){read(); next();}; ///first() reads the first line from a file and then calls the next() so that the first line is already stored in the class member variables and the next() already has something to process
        void next(); ///retrieve the next element from a file -- see filenor.cpp
        DataType current()const {return m_current;} ///return the current element to process with
        bool end()const{return m_end;} ///returns the file status. if status is norm -> true, false otherwise.

    private:
        DataType m_current; ///member current data along with the frequency
        Status m_fstatus; /// member file status
        std::ifstream m_file; ///member input file
        bool m_end; ///stores boolean status of the file
        int m_read;  ///the integer being read


        void read(); ///read the first element only
};

#endif // FILEENOR_H
