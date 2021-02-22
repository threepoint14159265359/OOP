#ifndef CHESSMATRIX_H
#define CHESSMATRIX_H

#include <vector>
#include <fstream>
#include <string>
#include <math.h> //floor and cmath

class ChessMatrix
{
public:

    enum ERRORS{CORRUPT_FILE, INDEX_OUT_OF_BOUND, NOT_A_CHESS_TYPE, ILLIGAL_MATRIX};


    //constructors
    ChessMatrix();
    ChessMatrix(const std::vector<int> &ivector);
    ChessMatrix(int size);
    ChessMatrix(const std::string &fileName);


    int getElemAt(int i, int j)const; //getting element at index i and j
    int getSize();
    ChessMatrix multiply(const ChessMatrix& iMatrix);
    ChessMatrix Add(const ChessMatrix& iMatrix);


    //operator overloading
    ChessMatrix operator*(ChessMatrix& iMatrix) const;
    ChessMatrix operator+(ChessMatrix& iMatrix) const;
    friend std::ostream& operator<<(std::ostream& streamObject, const ChessMatrix& iMatrix);

private:
    int m_size;
    std::vector<int> m_vector;
    bool isChessTypeMatrix();
    int ind(int i, int j)const ;
    double calcSizeFromLength(unsigned int size);
};

#endif // CHESSMATRIX_H
