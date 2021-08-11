// stonewt.cpp -- Stonewt methods
#include <iostream>
#include "stonewt.h"
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
