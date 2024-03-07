#include <iostream>
#include "List.h"

/* List_element Implementations */

// Constructor Overloaded
List_element::List_element(int n = 0, List_element* ptr = nullptr)
	: data(n)
	, next(ptr) {}


/* List Implementations */
// Array -> List, data transform constructor
List(const int* arr, int size)
{
	// Empty List
	if (head == nullptr)
	{
		std::cout << "List is empty, making a new list" << std::endl;
		// Head insert
		for (int i = size - 1; i >= 0; --i)
		{
			std::cout << "Prepeding [ " << arr[i] << " ] " << std::endl;
			cursor = head = new List_element(arr[i], head);
			size++;
		}
	}
	else
	{
		// Head insert
		for (int i = size - 1; i >= 0; --i)
		{
			std::cout << "Prepeding [ " << arr[i] << " ] " << std::endl;
			
			size++;
		}
	}
}

// TODO: Implement the following two constructors
List(const List& list); // Move constructor
~List(); // Destructor

// TODO: Test append
void List::append(int val)
{
	// Empty list
	if (this->head == nullptr)
	{
		std::cout << "Appending [ " << val << " ] " << std::endl;
		cursor = head = new List_element(val, head);
		size++;
	}
	else
	{
		std::cout << "Appending [ " << val << " ] " << std::endl;
		// TODO: Implement append
	}

}

void List::prepend(int val)
{
	// Empty list
	if (head == nullptr)
	{
		std::cout << "Prepending [ " << val << " ] " << std::endl;
		cursor = head = new List_element(val, head);
		size++;
	}
	else
	{
		std::cout << "Prepending [ " << val << " ] " << std::endl;
		head = new List_element(val, head);
		size++;
	}
}

void List::print()
{
	if (head == nullptr)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		List_element* temp = head;
		while (temp->next != nullptr)
		{
			std::cout << "[ " << temp->data << " ] -> ";
		}
		std::cout << "NULL" << std::endl;
	}
}

int List::getSize() const
{
	return this->size;
}

void List::printHead()
{
	if (this->head == nullptr)
	{
		std::cout << "NULL" << std::endl;
	}
	else if (List::getSize() <= 0)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		std::cout << "Head = [ " << this->head->data << " ]" << std::endl;
	}
}

List_element* List::getHead()
{
	if (this->head == nullptr)
	{
		std::cout << "NULL" << std::endl;
	}
	else if (List::getSize() <= 0)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		return this->head;
	}
}


// NOTES: 

/*
// C notation
// This is public by default
struct list_element
{
	list_element(int n = 0, list_element* ptr = 0) :
		d(n), next(ptr) {}

	int d;
	list_element* next;
};

// OR EQUIVALENTLY C++ notation

class list_element
{
public:
 
	// Constructor: initializes two elements, d and next as 0
	// What is 0 used for?
	// The null pointer which in C++11 is better written as nullptr
 
	list_element(int n = 0, list_element* ptr = 0) :
		d(n), next(ptr) {}

	int d;
	list_element* next;
};
*/
