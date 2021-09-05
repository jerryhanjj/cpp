#pragma once
// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_

#include <iostream>

// 抽象基类
class baseDMA
{
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);

private:
    char * lable;
    int rating;
};

class lacksDMA :public baseDMA
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];
public:
    lacksDMA(const char *c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);
    friend std::ostream & operator<<(std::ostream &os, const lacksDMA & ls);
};

class hasDMA:public baseDMA
{
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & hs);
private:
    char *style;
};

#endif // !DMA_H_
