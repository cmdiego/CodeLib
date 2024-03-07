#include <iostream>

using namespace std;	// scope resolution op

// reference to int
inline void swap(int& i, int& j)	// call by ref
{
	int temp = i;
	i = j;
	j = temp;
}

// overloading :)
inline void swap(double& i, double& j)
{
	double temp = i;
	i = j;
	j = temp;
}

int main()
{
	double m = 5, n = 10;
	// signature matching
	swap(m, n);
}