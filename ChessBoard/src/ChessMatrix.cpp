#include "ChessMatrix.h"


/***
By default the vector size is equal to a standard chess board which contains 32 colored spaces.
*/
ChessMatrix::ChessMatrix(){
    this->m_size = 8;
    this->m_vector={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
}

ChessMatrix::ChessMatrix(const std::vector<int> &ivector){
    //set the vector here
}

///Reading a file in the constructor
ChessMatrix::ChessMatrix(const std::string &fileName){
    std::fstream f(fileName);
    if (f.fail()){
        throw ERRORS::CORRUPT_FILE;
    }
    else{
        int e;
        while (f>>e){
            m_vector.push_back(e);
        }
        double n = calcSizeFromLength(m_vector.size());
        if (n==floor(n)){
            m_size=n;
        }
        else{
            throw ERRORS::INDEX_OUT_OF_BOUND;
        }
    }
}



///given a 1-D vector, we can find the size of the chess type matrix
double ChessMatrix::calcSizeFromLength(unsigned int size)
{
    return (-1+sqrt(1+8*size)) / 2;
}


/**
    A private method which returns the index of the entry of transformed matrix - a 1-D vector.
*/


int ChessMatrix::ind(int i, int j){
    return (m_size/2) * i + floor(j/2);
}


/*****
    If we have an entry at row i and column j, we can access its indexed-Value by the following function
***/
int ChessMatrix::indexEntry(int i, int j){
    if((i+j) % 2 == 0){
        int m = ind(i, j);
        return m_vector[m];
    }else{
        return 0;
    }
}
