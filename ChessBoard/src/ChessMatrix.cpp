#include "ChessMatrix.h"


//default
ChessMatrix::ChessMatrix(){
    m_size = 0;
}

/*
- Given a size we can auto generate a chessBoard indicating the non-zero digits by 1
- size can only by 2-by-2 4-by-4, 6 8 10 12 ... and so on
- the element these will store would be 2 8 18 32 50 ... and so on
- So, given size = 8, we would insert 32 elements which can be calculated by the formula given as LengthOfVector
*/
ChessMatrix::ChessMatrix(int size){
    if(size < 2){ //a chess with size smaller than 2 can not be justified.
        throw ERRORS::NOT_A_CHESS_TYPE;
    }
    this->m_size = size;
    unsigned int LengthOfVector = ceil(2*((double)size/(double)2)*((double)size/(double)2)); // double casting
    int element = 1;
    for(unsigned int i = 0; i< LengthOfVector; i++){
        m_vector.push_back(element);
    }
    if(not(isChessTypeMatrix())){
        m_size = 0;
        m_vector.clear();
        throw ERRORS::NOT_A_CHESS_TYPE;
    }
}

//copy constructor
ChessMatrix::ChessMatrix(const std::vector<int> &ivector){
    setChessMatrix(ivector);
}


//constructor with file
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

void ChessMatrix::setChessMatrix(const std::vector<int> &ivector){
    this->m_size = calcSizeFromLength(ivector.size());
    m_vector = ivector; //copy the vector
    if(not(this->isChessTypeMatrix())){ //check whether it's a chess type or not
        m_size = 0;
        m_vector.clear();
        throw ERRORS::NOT_A_CHESS_TYPE;
    }
}



//size n of an n-by-n matrix
unsigned int ChessMatrix::getSize()const{
    return m_size;
}




//finds the index of a given (ith row, jth column) entry in a single vector
int ChessMatrix::ind(int i, int j)const{
    return (m_size/2) * i + floor(j/2);
}





//If we have an entry at row i and column j, we can access its indexed-Value
//we just return non-zero element from the square
int ChessMatrix::getElemAt(unsigned int i, unsigned int j)const{
    if(i >= m_size || i < 0 || j >= m_size || j < 0){
        throw ERRORS::INDEX_OUT_OF_BOUND;
    }
    if(nonZeroSquares(i, j)){
        return m_vector[ind(i, j)];
    }
    return 0;
}

/*
-given a 1-D vector, we can find the size n, (n-by-n), of the chess type matrix
-chess type matrices are in the form 2*2, 4*4, 6*6, 8*8 and so on
-they store 2, 8, 18, 32 elements respectively. We store them in a single vector (to represent a single colour). This sequence is of the form An = 2n^2
-So, if given the number of elements, An (which is the length of the vector), we can calculate n.
*/
double ChessMatrix::calcSizeFromLength(unsigned int size){
    return 2 * sqrt(size/2);
}


/*
-a chess type matrix is always n-by-n where n = even
- 2 8 18 32 ... = 2n^2
-what if we want to find n???
-the n should always be integer cause it's the position of the given number in the sequence
*/
bool ChessMatrix::isChessTypeMatrix()const{
    double n = sqrt((double)m_vector.size()/(double)2);
    return m_size > 1 && n == (int) n; //checks whether the number is an integer <==> n =? floor(n)
}


/*
-given two indexes, check whether it corresponds to a non-zero number in the given matrix
-if the non-zero digits (same colored squares) are stored in (1,1) , (1,3) , (1, 5) and so on, then there sum is always even
**/
bool ChessMatrix::nonZeroSquares(unsigned int i, unsigned int j){
    return (i + j) % 2 == 0;
}



//Matrix Addition
//Only adds the matrix whose sizes are the same and both are Chess Type Matrices
ChessMatrix ChessMatrix::add(const ChessMatrix& a, const ChessMatrix& b){
    if(not(a.isChessTypeMatrix()) || not(b.isChessTypeMatrix())){
        throw ERRORS::NOT_A_CHESS_TYPE;
    }

    if(a.getSize() != b.getSize()){
        throw ERRORS::NOT_EQUAL_SIZE;
    }

    ChessMatrix sum(a); //throws NOT_A_CHESS_TYPE
    for (unsigned int i=0;i<a.m_vector.size();i++){
        sum.m_vector[i] += b.m_vector[i];
    }
    return sum;
}

/*
Standard matrix multiplication but only on Chess Type matrices
- must be square matrices
- must be n-by-n, where n is even
*/
ChessMatrix ChessMatrix::multiply(const ChessMatrix& a,const ChessMatrix& b)
{
    if(not(a.isChessTypeMatrix()) || not(b.isChessTypeMatrix())){
        throw ERRORS::NOT_A_CHESS_TYPE;
    }

    if(a.getSize() != b.getSize()){
        throw ERRORS::NOT_EQUAL_SIZE;
    }
    std::vector<int> result_vector;
    for (unsigned int i=0;i<a.m_size;i++){
        for (unsigned int j=0;j<b.m_size;j++){
            int sum = 0;
            if(nonZeroSquares(i, j)){
                for(unsigned int k = 0; k < a.m_size; k++){
                    sum += a.getElemAt(i, k) * b.getElemAt(k, j);
                }
                result_vector.push_back(sum);
            }
        }
    }
    ChessMatrix mul(result_vector);
    return mul;
}


//Some Operator Overloading
//outPutStream(<<)
std::ostream& operator<<(std::ostream& Stream,const ChessMatrix& iMatrix)
{
    Stream << "\t\t" << iMatrix.m_size <<"x"<<iMatrix.m_size << ": "<<std::endl;
    for (unsigned int i=0;i<iMatrix.m_size;i++)
    {
        for (unsigned int j=0;j<iMatrix.m_size;j++)
        {
            Stream << "\t"  << iMatrix.getElemAt(i,j);
        }
        Stream << "\n\n";
    }
    return Stream;
}


//addition(+)
ChessMatrix ChessMatrix::operator+(ChessMatrix& iMatrix){
    std::vector<int> sum_vector; //an empty matrix
    for(unsigned int i = 0; i<iMatrix.m_vector.size(); i++){
        sum_vector.push_back(this->m_vector.at(i) + iMatrix.m_vector.at(i));
    }
    ChessMatrix sum(sum_vector);
    return sum;
}

//multiplication(*)
ChessMatrix ChessMatrix::operator*(ChessMatrix& iMatrix){
    if(not(this->isChessTypeMatrix()) || not(iMatrix.isChessTypeMatrix())){
        throw ERRORS::NOT_A_CHESS_TYPE;
    }

    if(this->getSize() != iMatrix.getSize()){
        throw ERRORS::NOT_EQUAL_SIZE;
    }
    std::vector<int> result_vector;
    for (unsigned int i=0;i<this->m_size;i++){
        for (unsigned int j=0;j<this->m_size;j++){
            int sum = 0;
            if(nonZeroSquares(i, j)){
                for(unsigned int k = 0; k < this->m_size; k++){
                    sum += this->getElemAt(i, k) * iMatrix.getElemAt(k, j);
                }
                result_vector.push_back(sum);
            }
        }
    }
    ChessMatrix mul(result_vector);
    return mul;
}


