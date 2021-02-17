#include <iostream> 




class Point{
public: 

	Point(double x = 0, double y = 0): _x(x), _y(y) {}
	
	//setter
	void setPoint(double x, double y){
		this->_x = x;
		this->_y = y;
	}
	//getters
	double getX(){return _x;}
	double getY(){return _y;}
	
	//Operator Overloading (+)
	Point operator+(const Point &p) const{
		double new_x = this->_x + p._x;
		double new_y = this->_y + p._y;
		return Point(new_x, new_y);
	}
	//Opeartor Overloading (/)
	Point operator/(const int d) const{
		double new_x = this->_x / (double) d; 
		double new_y = this->_y / (double) d;
		return Point(new_x, new_y);
	}
private:
	double _x, _y;
};


int main(){
	Point p;
	std::cout << p.getX() << " " << p.getY() << std::endl;
	Point p1(10);
	std::cout << p1.getX() << " " << p1.getY() << std::endl;
	Point p2(1,1);
	std::cout << p2.getX() << " " << p2.getY() << std::endl;
	/*The following code will give an error because we can't call a method with an "unknown stuff"*/
	//Point p3(,10);
	//std::cout << p3.getX() << " " << p3.getY() << std::endl;
	
	Point P = p1 + p2;
	std::cout << P.getX() << " " << P.getY() << std::endl;
}
