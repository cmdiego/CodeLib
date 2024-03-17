#pragma once

#include <iostream>

class List_element
{
public:
	List_element(int n, List_element* ptr);

	int data;
	List_element* next;
};

class List
{
public:
	List() : head(nullptr), cursor(nullptr) {}

	// TODO: Implement the following two constructors
	List(const int* arr, int size); // Array -> List, data transfer constructor
	List(const List& list); // Move constructor
	~List(); // Destructor

	/* Module implementations */
	void prepend(int val);

	void append(int val);
	
	void print();
	
	int getSize() const;
	
	void printHead();

	void setHead(const int val);


	List_element* getHead();


private:
	int size = 0;
	List_element* head;
	List_element* tail; // TODO: ADD TO CONSTRUCTORS, MAKE SETTER, GETTER, PRINT
	List_element* cursor;
};

#pragma once


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