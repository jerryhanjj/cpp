#pragma once
// stonewt1.h -- revised definition for the Stonwt class
#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt();
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;

    operator int() const;
    operator double() const;
};

#endif // !STONEWT_H_
