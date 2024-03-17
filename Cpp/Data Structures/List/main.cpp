#include <iostream>
#include "List.h"

int main()
{
	List a;
	a.prepend(10);
	a.prepend(11);
	a.prepend(12);

	a.printHead();

	List b = List(a);

	std::cout << "List b: " << std::endl;
	b.printHead();
	b.setHead(20);

	std::cout << "List b: " << std::endl;
	b.printHead();
	b.print();

	std::cout << "List a: " << std::endl;
	a.printHead();
	a.print();

}
