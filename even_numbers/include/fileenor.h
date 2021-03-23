#ifndef FILEENOR_H
#define FILEENOR_H


#include <fstream>



enum Status{
    norm, abnorm
};


class fileEnor
{
    public:
        enum errors{currput_file};
        fileEnor(const std::string &file_name);
        void first(){next();}
        void next(); ///see fileenor.cpp
        int current()const{return m_current;}
        bool end()const{return m_end;}

    private:
        std::ifstream _file;
        int m_current; //current element from a sequencial input file of type int
        Status m_status;
        bool m_end;
        fileEnor(){}// does nothing - better to keep it prvitate
};

#endif // FILEENOR_H
