#ifndef CHESSMATRIX_H
#define CHESSMATRIX_H

#include <vector>
#include <fstream>
#include <string>
#include <math.h>

/**
    @uthor: Hussain Izhar
    Task: Assignment 1, Object Oriented Programming - Spring 2021
**/


class ChessMatrix
{
public:

    enum ERRORS{CORRUPT_FILE, INDEX_OUT_OF_BOUND, NOT_A_CHESS_TYPE, NOT_EQUAL_SIZE};
    ChessMatrix();
    ChessMatrix(const std::vector<int> &ivector);
    ChessMatrix(int size);
    ChessMatrix(const std::string &fileName);
    int getElemAt(unsigned int i, unsigned int j)const; //getting element at index i and j
    unsigned int getSize()const;
    void setChessMatrix(const std::vector<int> &ivector);
    static bool isEqual(const ChessMatrix &a, const ChessMatrix &b);
    static bool nonZeroSquares(unsigned int i, unsigned int j);
    static ChessMatrix multiply(const ChessMatrix& A, const ChessMatrix& B);
    static ChessMatrix add(const ChessMatrix& A, const ChessMatrix& B);


    //operator overloading
    ChessMatrix operator*(ChessMatrix& iMatrix);
    ChessMatrix operator+(ChessMatrix& iMatrix);
    friend std::ostream& operator<<(std::ostream& streamObject, const ChessMatrix& iMatrix);

private:
    unsigned int m_size;
    std::vector<int> m_vector;
    bool isChessTypeMatrix()const;
    int ind(int i, int j)const ;
    double calcSizeFromLength(unsigned int size);
};

#endif // CHESSMATRIX_H
