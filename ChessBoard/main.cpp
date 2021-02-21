#include <iostream>
#include "ChessMatrix.h"
using namespace std;

int main()
{
/**
    ChessMatrix m("matrix.txt");
    cout << m.getElemAt(0, 0) << endl;
    cout << m.getElemAt(0, 1) << endl;
    cout << m.getElemAt(0, 2) << endl;
    cout << m.getElemAt(0, 3) << endl;
    cout << m.getSize();
    cout << "\n\n\n";
**/

    vector<int> vect;
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    ChessMatrix m1(vect);
    cout << m1.getSize() << endl;

    return 0;
}
