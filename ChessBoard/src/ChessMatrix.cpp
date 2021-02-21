#include "ChessMatrix.h"
#include <iostream>

/*OK*/
/*******************************************************************************************
    By default the vector size is equal to a standard chess board which contains 32 colored squares.
***************************************************************************************************/
ChessMatrix::ChessMatrix(){
    this->m_size = 8;
    this->m_vector={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
}


/*OK*/
/********************************************************************************************
    Copy Constructor - Given a vector of integers as an input parameter
***************************************************************************************************/
ChessMatrix::ChessMatrix(const std::vector<int> &ivector){
    this->m_size = calcSizeFromLength(ivector.size());
    m_vector = ivector;
    if(not(this->isChessTypeMatrix())){
        m_size = 0;
        m_vector.clear();
        throw ERRORS::NOT_A_CHESS_TYPE;
    }

}


/*OK*/
/**************************************************************************************
    - Reading a file in the constructor
    - we must check if the chess type is a matrix type. If it's not, we raise an exception
    - So, we don't have to process the matrices that are not file CHESS TYPE
****************************************************************************************************/
ChessMatrix::ChessMatrix(const std::string &fileName){
    std::fstream f(fileName);
    if (f.fail()){
        throw ERRORS::CORRUPT_FILE;
    }
    int e;
    while(f >> e){
        m_vector.push_back(e);
    }
    m_size = calcSizeFromLength(m_vector.size());
    if(! this->isChessTypeMatrix()){
        m_size = 0;
        m_vector.clear();
        throw ERRORS::NOT_A_CHESS_TYPE;
    }
}


/*OK*/
/*********************************************************************************************************8
    This size indicates the actual size of the matrix as in whether it's a 2-by-2 or a n-by-n size.
************************************************************************************************************/
int ChessMatrix::getSize(){
    return m_size;
}



/*OK*/
/************************************************************************************************
    A private method which returns the index of the entry of transformed matrix - a 1-D vector.
**************************************************************************************************/
int ChessMatrix::ind(int i, int j){
    return (m_size/2) * i + floor(j/2);
}


/*OK*/
/***********************************************************************************
    - If we have an entry at row i and column j, we can access its indexed-Value
    - If the given indexes does not contain the non-zero elements, we simply return zero
    - in chess type matrix, the sum of the indexes of the non-zero entries is always even
*********************************************************************************************/
int ChessMatrix::getElemAt(int i, int j){
    if(i >= m_size || i < 0 || j >= m_size || j < 0){
        throw ERRORS::INDEX_OUT_OF_BOUND;
    }
    if((i+j) % 2 == 0){
        return m_vector[ind(i, j)];
    }
    return 0;
}

/*OK*/
/*****************************************************************************************************************
    -given a 1-D vector, we can find the size of the chess type matrix
    -chess type matrices are in the form 2*2, 4*4, 6*6, 8*8 and so on and so forth
    -storing 2, 8, 18, 32 elements respectively. This sequence is of the form An = 2n^2
    -So, if given the number of elements, An, we can calculate n, which is the position of that element in the sequence.
    -Like n = 1 for 2, n = 2 for 8 and so on. We multiply it by 2 so that we can find the exact size of the chess matrix
    -Like n = 2*1 for 2, n = 2*2 for 8 and so on.
********************************************************************************************************************************/
double ChessMatrix::calcSizeFromLength(unsigned int size){
    return 2 * sqrt(size/2);
}

/*OK*/
/**********************************************************************************************************
    -Check whether a given vector is chess type or not
    -We know the formula for the nth term of the sequence 2 8 18 32 ... = 2n^2
    -what if we want to find n???
    -the n should always be integer cause it's the position of the given number in the sequence
*************************************************************************************************************/
bool ChessMatrix::isChessTypeMatrix(){
    double n = sqrt((double)m_vector.size()/(double)2);
    return m_size > 1 && n == (int) n; ///checks whether the number is an integer <==> n =? floor(n)
}
