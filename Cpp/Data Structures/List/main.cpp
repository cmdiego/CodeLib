#include <iostream>
#include "List.h"

int main()
{
	List a, b;
	int data[10] = { 1, 2, 3, 4 };
	List a(data, 6);
	List e(data, 10);
	a.prepend(9);
	a.prepend(8);
	std::cout << "list a: ";
	a.print();

	for (int i = 0; i < 10; i++)
	{
		b.append(i * i);
		if (i == 0)
		{
			std::cout << "list b: " << ;
		}
		else
		{
			std::cout << ", ";
		}	
	}
}
