// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

int main()
{
    using std::cout;
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;  // 转换函数
    cout << "Covert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Covert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";
    return 0;
}