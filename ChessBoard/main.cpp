#include <iostream>
#include "ChessMatrix.h"
using namespace std;

int main()
{
    ChessMatrix m2(2);
    ChessMatrix m4(4);
    ChessMatrix m6("matrix.txt");
    ChessMatrix m8;
    ChessMatrix m10(10);
    ChessMatrix m12(12);
    ChessMatrix m14(14);



    cout << ChessMatrix::add(m6, m6) << endl;
    //cout << m12 << endl;
    //cout << m14 << endl;

    return 0;
}
