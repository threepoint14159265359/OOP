#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>


/*
    @uthor: Hussain Izhar
    Task: Assignment 1 Task 4, OOP, Spring 2021, ELTE
*/


class matrix{
public:

    enum ERRORS {corrupt_file,over_indexed, invalid_matrix, matrices_of_diff_size};
    /*Constructors*/
    matrix(){} //does nothing
    matrix(const std::vector<int> &i_vec); ///reads data from a single dimensional vector
    matrix(const std::string &filename); ///reads data from a file


    /*class methods*/
    unsigned int getSize()const{return m_size;}
    int getElem(unsigned int i, unsigned int j) const;

    /*static methods*/
    static matrix sum(const matrix &i_matrix1, const matrix &i_matrix2);
    static matrix multiply(const matrix &i_matrix1, const matrix &i_matrix2);
    friend std::ostream& operator<<(std::ostream& streamObject, const matrix& i_Matrix);

private:
    unsigned int m_size_of_block_matrix1;
    unsigned int m_size_of_block_matrix2;
    unsigned int m_size;
    std::vector<std::vector<int>> m_matrix1; ///block matrix 1
    std::vector<std::vector<int>> m_matrix2; ///block matrix 2
    std::vector<int> m_vector; ///This stores the whole data coming from the user

    bool is_block_type_matrix(const std::vector<int> &i_vec) const;
    bool is_block_type_matrix() const;

};

#endif
