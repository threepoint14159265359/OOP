#include "../Headers/Rnumbers.h"


/**
* getters
**/
int Rnumbers::getDenominator(){return this->denominator;}
int Rnumbers::getNumerator(){return this->numerater;}

int Rnumbers::show(){std::cout << this->numerater << "/" << this->denominator;}

void Rnumbers::add(Rnumbers inum){
    this->numerater = this->numerater*inum.denominator + this->denominator*inum.numerater;
    this->denominator = this->denominator * inum.denominator;
}
