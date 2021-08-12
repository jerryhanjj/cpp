// stonewt1.cpp -- Stonewt class methods + conversion functions
#include <iostream>
#include "stonewt1.h"
using std::cout;

// 默认构造函数
Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// 从英石构造对象
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::~Stonewt()
{
}

// 显示英石重量
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// 显示磅重量
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// 转换函数
Stonewt::operator double() const
{
    return pounds;
}

Stonewt::operator int() const
{
    // 如果 pounds 小数部分大于0.5则加 0.5之后 值 +1
    return int(pounds + 0.5);
}