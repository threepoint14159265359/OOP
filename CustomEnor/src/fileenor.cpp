#include "fileenor.h"

fileEnor::fileEnor(const string &filename){
    m_file.open(filename);
    if(m_file.fail()){
        throw errors::corrupt_file;
    }
}

void fileEnor::read(){
    ///read first number and stored it into m_read
    ///does two things for us:
        //1. It reads a number and store it in m_read
        //2. It decides the file status and store it in m_fstatus
   m_fstatus = (m_file >> m_read) ? norm : abnorm;
}



void fileEnor::next(){
    if( m_end = (m_fstatus == abnorm)){ /// if the file status is abnorm -> return the state of execution
        return;
    }
    ///the current number is stored in m_read
    m_current.rNum = m_read;
    ///start the frequency by 0 <- and then we will pre-increment the value
    m_current.rNum_frequency = 0;

    ///start reading the file (while the current element is the same which is being read, continue reading, stop otherwise.)
    while( (m_fstatus == norm) && (m_current.rNum == m_read)){
        ++m_current.rNum_frequency;
        read(); ///read the next element
    }
}
