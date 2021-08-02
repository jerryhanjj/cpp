// secref.cpp 
#include <iostream>
using namespace std;

int main()
{
    int rats = 101;
    int *pt = &rats;
    int & rodents = *pt;
    int bunnies = 50;
    pt = &bunnies;

    cout << rodents << endl;
    cout << *pt << endl;

    rodents = bunnies;
    cout << rats << endl;
    cout << rodents << endl;

    cout << &rats << endl;
    cout << &rodents << endl;
    cout << &bunnies << endl;

    return 0;
}