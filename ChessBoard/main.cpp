#include <iostream>
#include "ChessMatrix.h"
#include "menu.h"

/**
    @uthor: Hussain Izhar
    Task: Assignment 1, Object Oriented Programming - Spring 2021
**/



//#define NORMAL_MODE
#ifdef NORMAL_MODE

using namespace std;

int main()
{
    Menu test;
    test.run();

    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "ChessMatrix.h"


TEST_CASE("FILE CONSTRUCTOR", "WRONG INPUT DATA IN A FILE"){
    CHECK_THROWS(ChessMatrix m("WRONGINPUT.txt")); //must throw an exception
}

TEST_CASE("VECTOR CONSTRUCTOR", "WRONG INPUT DATA IN A VECTOR"){
    std::vector<int> wrong_vector = {332,11,22,33,44,33,44,55,4,33,22,33,44,33,22,33,44,33,22,33,44,33,22}; // the vector size is not a chess type matrix
    CHECK_THROWS(ChessMatrix m(wrong_vector));
}

TEST_CASE("SIZE CONSTRUCTOR", "WRONG SIZE"){
    int wrong_size = 13; //odd number can never be a chess type matrices
    CHECK_THROWS(ChessMatrix m(wrong_size));
}


TEST_CASE("NEGATIVE INDEXS", "VALUE AT ROW i COLUMN j IN A FILE"){
    int row = -1;
    int column = -1;
    ChessMatrix m1("matrix.txt");
    CHECK_THROWS(m1.getElemAt(row, column));
}

TEST_CASE("INDEXS OUT OF BOUND", "VALUE AT ROW i COLUMN j IN A FILE"){
    int row = 1;
    int column = 10; //In the file, we have a 10-by-10 matrix, and counting starts from zero. So, 10 is out of bound index
    ChessMatrix m1("matrix.txt");
    CHECK_THROWS(m1.getElemAt(row, column));
}

TEST_CASE("CORRECT INDEXES", "VALUE AT ROW I COLUMN j IN A FILE"){
    int row = 3, column = 7, value = 8483; // have check this manually
    ChessMatrix m("matrix.txt");
    CHECK(value == m.getElemAt(row, column));
}


TEST_CASE("SUM0", "DIFFERENT SIZES"){
    std::vector<int> vec1={1,2};
    ChessMatrix m1(vec1);
    std::vector<int> vec2={1,21,11,41,4,15,9,10};
    ChessMatrix m2(vec2);
    ChessMatrix result;
    CHECK_THROWS(result = m1 + m2); //must throw an error because their sizes are not equal
}

TEST_CASE("SUM1", "2-by-2 matrix"){
    std::vector<int> vec1 = {12,12};
    std::vector<int> vec2 = {1,2};
    std::vector <int> sum = {13,14}; // worked out by hand
    ChessMatrix Sum(sum);
    ChessMatrix m1(vec1);
    ChessMatrix m2(vec2);
    CHECK(ChessMatrix::isEqual(m1+m2, Sum));
}

TEST_CASE("SUM2", "6-by-6 matrix"){
    std::vector<int> vec1 = {12,12, 13, 14, 15,  12, 22, 1, 22,3, 3, 4,  3, 2, 3,4 ,3,4};
    std::vector<int> vec2 = {1,  2, 12 , 2 , 2,   3,  4, 5, 5 ,4 ,22,33,423,22,3,4,1,1};
    std::vector <int> sum = {13,14, 25,  16, 17,  15, 26,6, 27, 7, 25, 37, 426, 24, 6,8,4, 5}; //worked out by hand
    ChessMatrix Sum(sum);
    ChessMatrix m1(vec1);
    ChessMatrix m2(vec2);
    CHECK(ChessMatrix::isEqual(m1+m2, Sum));
}


TEST_CASE("MATRIX_MULT0", "DIFFERENT SIZES"){
    std::vector<int> vec1={1,2};
    ChessMatrix m1(vec1);
    std::vector<int> vec2={1,1,11,1,4,5,9,12};
    ChessMatrix m2(vec2);
    ChessMatrix result;
    CHECK_THROWS(result = m1 * m2); //must throw an error because their sizes are not equal
}

TEST_CASE("MATRIX_MULT1", "2-by-2 matrix"){
    std::vector<int> vec1 = {12,12};
    std::vector<int> vec2 = {1,2};
    std::vector <int> prod = {12,24}; //worked out by hand
    ChessMatrix matrixMult(prod);
    ChessMatrix m1(vec1);
    ChessMatrix m2(vec2);
    CHECK(ChessMatrix::isEqual(m1*m2, matrixMult));
}

TEST_CASE("MATRIX_MULT2", "6-by-6 matrix"){
    std::vector<int> vec1 = {12,12, 13, 14, 15,  12, 22, 1, 22,3, 3, 4,  3, 2, 3,4 ,3,4};
    std::vector<int> vec2 = {1,  2, 12 , 2 , 2,   3,  4, 5, 5 ,4 ,22,33,423,22,3,4,1,1};
    std::vector <int> prod = {5559,370,243,136,370,549,9332,533,335,34,76,112,1280,82,55,36,78,115}; //worked out by hand
    ChessMatrix matrixMult(prod);
    ChessMatrix m1(vec1);
    ChessMatrix m2(vec2);
    CHECK(ChessMatrix::isEqual(m1*m2, matrixMult));
}


#endif



