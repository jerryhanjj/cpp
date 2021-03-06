## 第12章 类和动态内存分配

### 概述

- 对类成员使用动态内存分配
- 隐式和显式复制构造函数
- 隐式和显式重载赋值运算符
- 在构造函数中使用new所必须完成的工作
- 使用静态类成员
- 将定位new运算符用于对象
- 使用指向对象的指针
- 实现队列抽象数据类型

介绍如何对类使用new和delete以及如何处理由于使用动态内存引起的一些微妙的问题。

### 12.1 动态内存和类

静态类成员：无论创建了多少对象，程序之创建一个静态类变量副本，**类的所有对象共享同一个静态成员**

`strngbad.h` 中 `StringBad` 类静态成员 `num_strings` 
```c
class StringBad
{
private:
    ...
    char * str;
    static int num_strings;
    ...
}
```

静态成员变量：
- 类的所有对象共享一个静态成员
- 不能在类声明中初始化，static const int 和 enum 枚举类型除外
- 在类函数实现的文件中初始化

不能对字符指针直接赋值，字符串保存在堆中，对象中仅保存了地址
```c
str = s;    // 不能这样直接赋值
```



