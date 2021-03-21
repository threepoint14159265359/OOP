#include "matrix.h"


/*
    @uthor: Hussain Izhar
    Task: Assignment 1 Task 4, OOP, Spring 2021, ELTE
*/



/**READS DATA FROM A Vector*/
matrix::matrix(const std::vector<int> &i_vec){
    if (!this->is_block_type_matrix(i_vec)){//first check if it's a block type matrix
        throw ERRORS::invalid_matrix;
    }
    int size = i_vec.size();
    bool isEven = (size % 2 == 0);
    if(isEven){
        m_size = sqrt(size * 2);
    }else{
        m_size = sqrt((size*2)-1);
    }
    m_size_of_block_matrix1 = ceil(m_size/ 2); //the small matrix in case of even size matrices
    m_size_of_block_matrix2 = m_size - m_size_of_block_matrix1;
    m_matrix1.resize(m_size_of_block_matrix1);
    m_matrix2.resize(m_size_of_block_matrix2);
    m_vector = i_vec;

    int index = 0;
    for(unsigned int i = 0; i<m_size_of_block_matrix1; i++){
        for(unsigned int j = 0; j < m_size_of_block_matrix1; j++ ){
            m_matrix1[i].push_back(i_vec[index]);
            index++;
        }
    }

    for(unsigned int i = 0; i<m_size_of_block_matrix2; i++){
        for(unsigned int j = 0; j < m_size_of_block_matrix2; j++ ){
            m_matrix2[i].push_back(i_vec[index]);
            index++;
        }
    }
}

/**READS DATA FROM A FILE*/
matrix::matrix(const std::string &filename){
    std::fstream f(filename);
    if (f.fail()){
        throw ERRORS::corrupt_file;
    }
    int e;
    while(f >> e){
        m_vector.push_back(e);
    }
    if (!this->is_block_type_matrix(m_vector)){//first check if it's a block type matrix
        throw ERRORS::invalid_matrix;
    }

    int size = m_vector.size();
    bool isEven = (size % 2 == 0);
    if(isEven){
        m_size = sqrt(size * 2);
    }else{
        m_size = sqrt((size*2)-1);
    }
    m_size_of_block_matrix1 = ceil(m_size/ 2);
    m_size_of_block_matrix2 = m_size - m_size_of_block_matrix1;
    m_matrix1.resize(m_size_of_block_matrix1);
    m_matrix2.resize(m_size_of_block_matrix2);

    int index = 0;
    for(unsigned int i = 0; i<m_size_of_block_matrix1; i++){
        for(unsigned int j = 0; j < m_size_of_block_matrix1; j++ ){
            m_matrix1[i].push_back(m_vector[index]);
            index++;
        }
    }

    for(unsigned int i = 0; i<m_size_of_block_matrix2; i++){
        for(unsigned int j = 0; j < m_size_of_block_matrix2; j++ ){
            m_matrix2[i].push_back(m_vector[index]);
            index++;
        }
    }
}


int matrix::getElem(unsigned int i, unsigned int j)const{
    if(i >= m_size || j >= m_size || i < 0 || j < 0){
        throw ERRORS::over_indexed;
    }
    bool isEven = (this->m_size % 2 == 0);
    if(i < m_size_of_block_matrix1 && j < m_size_of_block_matrix1){
        return m_matrix1[i][j];
    }
    if(isEven && (i >= m_size_of_block_matrix1 && j >= m_size_of_block_matrix1)){
        return m_matrix2[i - m_size_of_block_matrix2][j - m_size_of_block_matrix2];
    }
    if(!isEven && (i >= m_size_of_block_matrix1 && j >= m_size_of_block_matrix1)){
        return m_matrix2[i - m_size_of_block_matrix2 + 1][j - m_size_of_block_matrix2 + 1];
    }
    return 0;
}


matrix matrix::sum(const matrix& A, const matrix &B){
    if(!(A.is_block_type_matrix() || !(B.is_block_type_matrix()))){
        throw ERRORS::invalid_matrix;
    }
    if(A.getSize() != B.getSize()){
        throw ERRORS::matrices_of_diff_size;
    }
    matrix sum(A.m_vector); //the size of the resulting vector must be equal to the coming input vectors

    for(unsigned int i = 0; i< A.m_size_of_block_matrix1; i++){
        for(unsigned int j = 0; j< A.m_size_of_block_matrix1; j++){
            sum.m_matrix1[i][j] = A.m_matrix1[i][j] + B.m_matrix1[i][j];
        }
    }


    for(unsigned int i = 0; i < A.m_size_of_block_matrix2; i++){
        for(unsigned int j = 0; j < A.m_size_of_block_matrix2; j++){
            sum.m_matrix2[i][j] = A.m_matrix2[i][j] + B.m_matrix2[i][j];
        }
    }

    return sum;
}


matrix matrix::multiply(const matrix &A, const matrix &B){
    if(!(A.is_block_type_matrix() || !(B.is_block_type_matrix()))){
        throw ERRORS::invalid_matrix;
    }
    if(A.getSize() != B.getSize()){
        throw ERRORS::matrices_of_diff_size;
    }
    std::vector<int> res_vec;
    for (unsigned int i=0;i<A.m_size;i++){
        for (unsigned int j=0;j<A.m_size;j++){
            int sum = 0;
            for(unsigned int k = 0; k < A.m_size; k++){
                    sum += A.getElem(i, k) * B.getElem(k, j);
            }
            if(sum > 0){
                res_vec.push_back(sum);
            }
        }
    }
    matrix mult(res_vec);
    return  mult;
}


bool matrix::is_block_type_matrix(const std::vector<int> &i_vec)const{
    int size = i_vec.size();
    if (size % 2 != 0){
        return sqrt(size*2 -1) == floor(sqrt(size*2 -1));
    }else{
        return sqrt(size * 2) == floor(sqrt(size * 2));
    }
}


bool matrix::is_block_type_matrix()const{
    int size = this->m_vector.size();
    if (size % 2 != 0){
        return sqrt(size*2 -1) == floor(sqrt(size*2 -1));
    }else{
        return sqrt(size * 2) == floor(sqrt(size * 2));
    }
}


std::ostream& operator<<(std::ostream& Stream,const matrix& iMatrix)
{
    Stream << "\t\t" << iMatrix.m_size <<"x"<<iMatrix.m_size << ": "<<std::endl;
    for (unsigned int i=0;i<iMatrix.m_size;i++)
    {
        for (unsigned int j=0;j<iMatrix.m_size;j++)
        {
            Stream << "\t"  << iMatrix.getElem(i,j);
        }
        Stream << "\n\n";
    }
    return Stream;
}



