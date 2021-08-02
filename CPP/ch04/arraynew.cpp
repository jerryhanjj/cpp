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

    p = p + 1;          // ָ����һ��Ԫ�أ������鱾���ϲ�ͬ�����֣����ڴ���p��ֵ�ı�һ��double�ĵ�ַ
    cout << *p << endl;
    cout << p << endl;

    p = p - 1;
    cout << p << endl;
    cout << *p << endl;

    delete[] p;
    return 0;
}