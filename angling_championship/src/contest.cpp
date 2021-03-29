#include "contest.h"
#include <iostream>
using namespace std;

contest::contest(const std::string &filename){
    _file.open(filename);
    if(_file.fail()){
        throw errors::corrupt_file;
    }
}


void contest::next(){
    std::string line;
    std::getline(_file, line, '\n');
    m_current.counter= 0;
    if(!(m_end = _file.fail() || line == "")){
        std::istringstream is(line);
        is >> m_current.angler_name >> m_current.contest_id;
        std::string fish;
        int size;
        for( is >> fish >> size; !is.fail(); is >> fish >> size){
            m_current.counter++;
        }
    }
}



