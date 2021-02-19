#include "cirlce.h"


//constructor
//Circle::Circle(Point c, double r = 0): center(c), radius(r){} ///not working again
Circle::Circle(){
    this->center = Point();
    this->radius = 0;
}

Circle::Circle(Point c, double r){
    this->center = c;
    this->radius = r;
}

//getters
double Circle::getRadius(){return this->radius;}
Point Circle::getCenter(){return this->center;}


//area
double Circle::area() const{
	double pi = 3.1415;
	return pi * this->radius * this->radius;
}

//isInside
bool Circle::isInside(const Point &p) const{
	return center.dist(p) < this->radius;
}

//ostream operator overloading
std::ostream &operator<<(std::ostream &stream, Circle &c){
    stream <<  " (" << c.center.getX() << ", " << c.center.getY() << ") r = " << c.getRadius();
    return stream;
}
