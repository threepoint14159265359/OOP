#include "fileenor.h"

fileEnor::fileEnor(const std::string &filename){
    _file.open(filename);
    if(_file.fail()){
        throw errors::currput_file;
    }
}



void fileEnor::next(){
    int num;
    m_status = (_file >> num) ? norm : abnorm;
    if(m_end = (m_status == abnorm)){
        return; //if it's the end of the file, don't read
    }
    m_current = num; //current is now
}


