// strngbad.cpp -- StringBad class methods
#include <iostream>
#include <cstring>
#include "strngbad.h"

using std::cout;

// 初始化静态变量
int StringBad::num_strings = 0;

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;   // 释放 new 分配的空间
}

std::ostream &operator<<(std::ostream &os, const StringBad &obj)
{
    os << obj.str;
    return os;
}