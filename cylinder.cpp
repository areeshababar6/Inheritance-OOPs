#include<iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int = 0, int = 0);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	void quad();
	void print();
};
Point::Point(int xa, int ya)
{
	x = xa; y = ya;
}
void Point::setX(int X)
{
	x = X;
}
void Point::setY(int Y)
{
	y = Y;
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
void Point::quad()
{
	if (x == 0 && y == 0)
		cout << " Point lies on origin." << endl;
	else if (x > 0 && y > 0)
		cout << " Point lies in 1st quadrant." << endl;
	else if (x < 0 && y > 0)
		cout << " Point lies in 2nd quadrant." << endl;
	else if (x < 0 && y < 0)
		cout << " Point lies in 3rd quadrant." << endl;
	else if (x > 0 && y < 0)
		cout << " Point lies in 4th quadrant." << endl;
}
void Point::print()
{
	cout << " ( " << x << " , " << y << " )" << endl;
	quad();
}

//--------------------------------------------
class Circle :public Point
{
private:
	double r;
public:
	Circle(int = 0, int = 0, double = 0);
	void area();
	void circum();
	void setR(double);
	void setCenter(int, int);
	double getR();
	void display();
};
Circle::Circle(int x, int y, double rad)
{
	setX(x); setY(y);
	r = rad;
}
void Circle::area()
{
	cout << " Area: " << 3.14 * r * r << endl;
}
void Circle::circum()
{
	cout << " Circumference: " << 2 * 3.14 * r << endl;
}
void Circle::setCenter(int x, int y)
{
	setX(x); setY(y);
}
void Circle::setR(double Rad)
{
	r = Rad;
}
double Circle::getR()
{
	return r;
}
void Circle::display()
{
	cout << " Radius: " << r << endl;
	cout << " Center: ";
	print();
	area();
	circum();
}
//---------------------------------------------------------

class Cylinder:public Circle
{
private:
	int h;
public:
	Cylinder(int = 0, int = 0, double = 0, int = 0);
	void setH(int);
	int getH();
	void show();
	void volume();
};
Cylinder::Cylinder(int x, int y, double r, int H)
{
	setCenter(x, y);
	setR(r);
	h = H;
}
void Cylinder::setH(int H)
{
	h = H;
}
int Cylinder::getH()
{
	return h;
}
void Cylinder :: show()
{
	cout << " Height: " << h << endl;
	cout << " Base Radius: " << getR() << endl;
	cout << " Base center: ";
	print();
	volume();
}
void Cylinder::volume()
{
	cout << " Volume of cylinder: " << 3.14 * getR() * getR() * h << endl;
}

int main()
{
	int x, y, h;
	double r;

	cout << " Enter coordinates of point: (x,y) ";
	cin >> x >> y;
	Point p(x, y);
	p.print();

	cout << "\n\n Enter details of circle..." << endl;
	cout << " Enter radius: ";
	cin >> r;
	cout << " Enter center coordinates: (x,y)";
	cin >> x >> y;
	Circle c(x, y, r);
	c.display();

	cout << "\n\n Enter details of cylinder..." << endl;
	cout << " Enter height: ";
	cin >> h;
	cout << " Enter radius of base: ";
	cin >> r;
	cout << " Enter coordinates of center of base: (x,y)";
	cin >> x >> y;

	Cylinder C(x, y, r, h);
	C.show();

	return 0;
}