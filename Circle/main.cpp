#include <iostream>
#include "Point.h"
#include "cirlce.h"


using namespace std;

int main()
{
    //single declaration
    Point p1;
    Point p2;
    Circle c1;
    std::cout << "p1.x = " << p1.getX() << " " << "p1.y = " << p1.getY() << std::endl;
    std::cout << "center = (" << c1.getCenter().getX() << " , "  << c1.getCenter().getY() << ")" << " " << "c1.y = " << c1.getRadius() << std::endl; //why don't we overload the ostream "<<" operator for both circle and point??!


    std::cout << p1 << p2 << std::endl; //this way is super easy
    std::cout << c1 << std::endl;


    ///Operations
    Point point1(1,2);
    Point point2(4,4);
    std::cout << point1 << " + " << point2 << " = ";
    Point point = point1 + point2;
    std::cout << point << std::endl;

    std::cout << point1.dist(point2) << std::endl;


    Circle circle1(point1, 5);
    std::cout << circle1 << std::endl;
    std::cout << "area: " << circle1.area() <<std::endl;
    std::cout << "is inside: " << circle1.isInside(point1) << std::endl; // default numeric value of true is 1 and false is 0
    std::cout << "is inside: " << circle1.isInside(point2);

    return 0;
}
