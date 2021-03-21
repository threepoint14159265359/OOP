#include "matrix.h"

/*
    @uthor: Hussain Izhar
    Task: Assignment 1 Task 4, OOP, Spring 2021, ELTE
*/


using std::cout;
using std::endl;

int main()
{
    //Quick Check
    matrix m1("matrix.txt");
    matrix m2("matrix.txt");
    cout << m1;
    cout << m2;
    std::cout << matrix::multiply(m1, m2);
    std::cout << matrix::sum(m1, m2);
    std::cout << m1.getElem(0,1);
}
