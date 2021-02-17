#include <iostream>


using namespace std;


class Rnumbers{
public:
    int getDenominator();
    int getNumerator();
    void show();
    void add(Rnumbers inum);
    void multiply(Rnumbers inum);
    void divide(Rnumbers);

private:
    int numerater, denominator;
};
