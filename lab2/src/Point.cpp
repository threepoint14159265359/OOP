#include "Point.h"
#include <cmath>
//constructor
//Point::Point(double x = 0, double y = 0): _x(x), _y(y) {} //this is not working for now

Point::Point(){
    this->_x = 0;
    this->_y = 0;
}
Point::Point(double x, double y){
    this->_x = x;
    this->_y = y;
}


//setters
void Point::setX(double ix){this->_x = ix;}
void Point::setY(double iy){this->_y = iy;}


//getters
double Point::getX(){return _x;}
double Point::getY(){return _y;}


double Point::dist(Point p)const{
	return sqrt((_x- p.getX() )*(_x - p.getX()) + (_y - p.getY()) * (_y - p.getY()));
}


//Operator Overloading (+)
Point Point::operator+(const Point &p) const{
	double new_x = this->_x + p._x;
	double new_y = this->_y + p._y;
	return Point(new_x, new_y);
}


//Opeartor Overloading (/) ... if we have more than one points, we can find their center.
Point Point::operator/(const int &d) const{
	double new_x = this->_x / (double) d;
	double new_y = this->_y / (double) d;
	return Point(new_x, new_y);
}

//overloading << operator so that we could use std::cout << Point; OR even file << Point.
std::ostream &operator<<(std::ostream &stream, Point &p){
    stream << "("<< p.getX() << ", " << p.getY() << ")";
}
