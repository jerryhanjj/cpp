// arraynew.cpp -- using the new operator for array
#include <iostream>
using namespace std;

int main()
{
    double *p = new double[3];
    p[0] = 0.2;
    p[1] = 0.5;
    p[2] = 0.8;
    cout << p << endl;
    cout << *p << endl;

    p = p + 1;          // 指向下一个元素，与数组本质上不同的体现，在内存上p的值改变一个double的地址
    cout << *p << endl;
    cout << p << endl;

    p = p - 1;
    cout << p << endl;
    cout << *p << endl;

    delete[] p;
    return 0;
}