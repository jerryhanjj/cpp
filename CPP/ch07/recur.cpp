// recur.cpp -- using recursion
#include <iostream>
using namespace std;

void countdown(int n)
{
    cout << "Counting down ..." << n << " at " << &n << endl;
    if (n > 0)
    {
        countdown(n - 1);
    }
    cout << n << ": Kaboom!" << " at " << &n << endl;
}

int main()
{
    countdown(4);
    return 0;
}