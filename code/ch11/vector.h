#pragma once
// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode { RECT, POL };
    private:
        double x;   // 横坐标
        double y;   // 纵坐标
        double mag; // 向量长度
        double ang; // 向量方向
        Mode mode;  // 直角坐标还是极坐标
    private:
        // methods
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        ~Vector();

        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return mag; }
        double angval() const { return ang; }

        void polar_mode();
        void rect_mode();
        void reset(double n1, double n2, Mode form = RECT);

        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;   // 减法运算符
        Vector operator-() const;      // 负号运算符，如 -x
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}   // end namespace VECTOR

#endif
