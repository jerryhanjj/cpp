// numstr.cpp -- following number input with line input
// program 4.6, page 81
#include <iostream>
using namespace std;

int main()
{
    cout << "What years was your house built?\n";
    int year;
    (cin >> year).get();    // 使用 cin >> year; 换行符将被下面的 getline 读取导致不能输入address的值
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Years built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}