#include <iostream>

using namespace std;

int main()
{
    int i = 9, j = 3;
    cout << "i: " << i << " j: " << j << endl;
    {
        cout << "i is: " << i << " j is: " << j << endl;    
    }
    cout << "i is: " << i << " j is: " << j << endl;
}