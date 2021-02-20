#ifndef CHESSMATRIX_H
#define CHESSMATRIX_H

#include <vector>
#include <fstream>
#include <string>
#include <math.h>

class ChessMatrix
{
public:

    enum ERRORS{CORRUPT_FILE, INDEX_OUT_OF_BOUND};

    //constructors
    ChessMatrix();
    ChessMatrix(const std::vector<int> &ivector);
    //ChessMatrix(int size); ///I am not sure if we can pass in the size of a matrix
    ChessMatrix(const std::string &fileName);
    int indexEntry(int i, int j);


    //addition


    //multiplication

private:
    int m_size;
    std::vector<int> m_vector;
    bool isChessBoardMatrix();
    int ind(int i, int j);
    double calcSizeFromLength(unsigned int size);
};

#endif // CHESSMATRIX_H
