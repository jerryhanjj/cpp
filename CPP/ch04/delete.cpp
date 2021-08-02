// delete.cpp -- using the delete operator
#include <iostream>
#include <cstring>
using namespace std;

char * getname()
{
    char temp[80];
    cout << "enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    return pn;
}

int main()
{
    char * name;
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;

    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;

    return 0;
}