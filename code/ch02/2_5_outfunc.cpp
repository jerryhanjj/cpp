//
// Created by han on 25-7-16.
//
#include <iostream>

void simon(int);

int main()
{
    using namespace std;
    simon(3);
    cout << "Pick a integer: ";
    int count;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;
    return 0;
}

void simon(int n)
{
    using namespace std;
    cout << "Simon says touch your toes " << n << " times. " << endl;
}
