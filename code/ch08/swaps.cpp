// swaps.cpp
#include <iostream>
using namespace std;

void swapr(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int wallet1 = 300;
    int wallet2 = 500;

    swapr(wallet1, wallet2);

    cout << wallet1 << " " << wallet2 << endl;

    return 0;
}