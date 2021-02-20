#include <iostream>
#include "ChessMatrix.h"
using namespace std;

int main()
{
    ChessMatrix m("matrix.txt");
    cout << m.indexEntry(0, 0) << endl;
    cout << m.indexEntry(0, 1) << endl;
    cout << m.indexEntry(0, 2) << endl;
    cout << m.indexEntry(0, 3) << endl;
    cout << m.indexEntry(0, 4) << endl;
    cout << m.indexEntry(0, 5) << endl;


    return 0;
}
