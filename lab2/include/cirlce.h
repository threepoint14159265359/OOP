#ifndef CIRLCE_H
#define CIRLCE_H

#include "Point.h"
#include <ostream>
class Circle
{
public:
	//constructor
	Circle();
	Circle(Point c, double r);

	//setters
	void setCenter(Point p);
	void SetRadius(double r);

	//getters
	double getRadius();
	Point getCenter();

	//area
	double area() const;

	//is a point inside a cirle
	bool isInside(const Point &p) const;


    //ostream operator overloading
    friend std::ostream &operator<<(std::ostream &os, Circle &c); //a friend function can access the private attributes of the class circle

private:
	Point center; double radius;
};

#endif // CIRLCE_H
