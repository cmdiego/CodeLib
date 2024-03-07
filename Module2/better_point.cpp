#include <iostream>

using namespace std;


class point 
{
	point() { this->x = 0.0, this->y = 0.0; }

public:
	void setX(double val) { x = val; };
	void setY(double val) { y = val; };
	double getX() const { return x; };
	double getY() const { return y; };

	point& operator+(point& p1)
	{
		point& sum = point( p1.x + this->x, p1.y + this->y );

		return sum;
	}

	ostream& operator<< (ostream& out, const point& p)
	{
		out << "( " << p.getX() << ", " << p.getY() << " )";
		return out;
	}
private:
	double x, y;
};




int main()
{
	point a = { 3.5, 2.5 }, b = { 2.5, 4.5 }, c;
	cout << "a = " << a << " b = " << b << endl;
	cout << " sum = " << a + b << endl;
}
