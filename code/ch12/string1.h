#pragma once
// string1.h -- fixed and augmented string class defintion
#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;   // cin input limit
public:
    String();
    String(const char * s); // 构造函数
    String(const String &); // 复制构造函数
    ~String();

    int length() const { return len; }
    static int HowMany();

    // 运算符重载函数 成员函数
    String & operator=(const String &);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;

    // 重载运算符 友元函数
    friend bool operator<(const String & st1, const String & st2);
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator==(const String & st1, const String & st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
};

#endif