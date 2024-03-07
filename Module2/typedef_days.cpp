#include <iostream>

using namespace std;

typedef enum days 
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THRUSDAY,
	FRIDAY,
	SAT
};


// Overload operator '++' for days
// Gets us the next day, e.g. an autoincrement for days
inline days operator++(days &d)
{
	return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

// Overload operator '<<' is usually left bit shift
// Redefined with two parameters
// Param1: Direct reference to the ostream
// Param2: Non-mutable reference to the day
ostream& operator<<(ostream& out, const days& d)
{
	switch (d)
	{
	case SUNDAY:
		out << "SUNDAY";
		break;
	case MONDAY:
		out << "MONDAY";
		break;
	}

	return out;
}

//int main()
//{
//	days d = MONDAY, e;
//	e = ++d;
//	cout << d << '\t' << endl;
//}