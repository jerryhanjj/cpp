#pragma once
// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
public:
    Stonewt();
    Stonewt(double lbs);    
    Stonewt(int stn, double lbs);
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;

private:
    enum 
    {
        Lbs_per_stn = 14
    };

    int stone;
    double pds_left;
    double pounds;
};

#endif // !STONEWT_H_
