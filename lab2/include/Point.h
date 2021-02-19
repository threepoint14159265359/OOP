#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
    //constructor
	Point();
	Point(double x, double y);

	//getters
	double getX();
	double getY();

	//setters
	void setX(double ix);
	void setY(double iy);

	//distance formula
	double dist(Point p) const;


	//constructor overloading
	Point operator+(const Point &p) const;
    Point operator/(const int &d) const;

    //ostream operator:
    friend std::ostream& operator<<(std::ostream& stream, Point &p);

private:
	double _x, _y;
};

#endif // POINT_H
