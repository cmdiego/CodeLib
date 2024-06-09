#include <iostream>
#include "List.h"

/* List_element Implementations */

// Constructor Overloaded
List_element::List_element(int n = 0, List_element* ptr = nullptr)
	: data(n)
	, next(ptr) {}


/* List Implementations */
// Array -> List, data transform constructor
List::List(const int* arr, int size)
{
	// Empty List
	if (this->head == nullptr)
	{
		std::cout << "List is empty, making a new list" << std::endl;
		// Head insert
		for (int i = size - 1; i >= 0; --i)
		{
			std::cout << "Prepeding [ " << arr[i] << " ] " << std::endl;
			List::prepend(arr[i]);
		}
	}
	else
	{
		// Head insert
		for (int i = size - 1; i >= 0; --i)
		{
			std::cout << "Prepeding [ " << arr[i] << " ] " << std::endl;
			this->size++;
		}
	}
}

List::List(const List& list)
{
	if (list.head == 0)
	{
		this->head = this->tail = this->cursor = 0;
		this->size = 0;
	}
	else
	{
		for (this->cursor = list.head; this->cursor != 0; this->cursor = this->cursor->next)
		{
			// Head insert, flips the list passed
			//this->head = new List_element(this->cursor->data, this->head);
			
			// Tail insert, keeps order the same
			List::prepend(this->cursor->data);
		}
		this->cursor = this->head;
	}
}

List::~List()
{
	while(this->head != nullptr)
	{
		List_element* next_ptr = this->head->next;
		delete(this->head);
		this->head = this->cursor = next_ptr;
	}
}

void List::append(int val)
{
	// Empty list
	if (this->head == nullptr)
	{
		std::cout << "Appending [ " << val << " ] " << std::endl;
		this->tail = this->head = new List_element(val, this->head);
		this->size++;
	}
	else
	{
		std::cout << "Appending [ " << val << " ] " << std::endl;
		// Tail insert
		List_element* prev_tail = this->tail;
		this->tail = new List_element(val, nullptr);
		prev_tail->next = this->tail;
		this->size++;
	}
}

void List::prepend(int val)
{
	// Empty list
	if (this->head == nullptr)
	{
		this->tail = this->cursor = this->head = new List_element(val, this->head);
		this->size++;
	}
	else
	{
		// Head insert
		this->head = new List_element(val, this->head);
		this->size++;
	}
}

void List::print()
{
	if (this->head == nullptr)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		for (this->cursor = this->head; this->cursor != nullptr; this->cursor = this->cursor->next)
		{
			std::cout << "[ " << this->cursor->data << " ] ->";
		}	
		std::cout << " NULL" << std::endl;
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

void List::setHead(const int val)
{
	this->head->data = val;
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
