#include <iostream>
#include "ChessMatrix.h"
using namespace std;

int main()
{
    ChessMatrix m2("matrix.txt");
    //ChessMatrix m1("matrix.txt");
    //ChessMatrix m3(-2);
    //ChessMatrix m4(2);
    cout << m2.getElemAt(0,1) << endl;
    cout << m2+m2 << endl;
    cout << m2*m2 << endl;



    return 0;
}
