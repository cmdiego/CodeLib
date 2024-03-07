#include <iostream>

using namespace std;

template<class T1, class T2>

/*
	@brief: 
			src: incoming data, const correctness meaning NOT mutable
			static_cast<T2>: safe casting
*/
void copy(const T1 src[], T2 destination[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		destination[i] = static_cast<T2>(src[i]); // error if no safe casting
	}
}