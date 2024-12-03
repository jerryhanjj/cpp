// dma.cpp -- dma class methods
#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char * l, int r)
{
    lable = new char[std::strlen(l) + 1];
    std::strcpy(lable, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    lable = new char[std::strlen(rs.lable) + 1];
    std::strcpy(lable, rs.lable);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete[] lable;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
    {
        return *this;
    }

    delete[] lable;
    lable = new char[std::strlen(rs.lable) + 1];
    std::strcpy(lable, rs.lable);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Lable: " << rs.lable << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const baseDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const baseDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r)
    :baseDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
    :baseDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

hasDMA::hasDMA(const char * s, const char * l, int r)
    :baseDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
    :baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
    :baseDMA(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
    {
        return *this;
    }
    baseDMA::operator=(hs); // 基类拷贝构造函数
    delete[] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}


