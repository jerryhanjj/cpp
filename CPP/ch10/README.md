## 对象和类

### 10.1 面向对象

- 面向对象编程(OOP)
- 实现接口
- 数据存储

### 10.2 抽象和类

指定基本类型时，完成了三项工作：
- 决定数据对象需要的内存
- 决定如何解释内存中的位
- 决定可使用数据对象执行的操作或者方法

对于内置类型，有关操作的信息被内置到编译器中。对于用户自定义的类型，必须自己提供这些信息

- 访问控制  
- 数据隐藏

类的默认访问类型是 private

共有部分的成员函数构成了设计的抽象部分——公有接口；将数据封装到私有部分中可以保护数据的完整性，被称为数据隐藏

```c
class World
{
    float mass; // private 类型
    ...
public:
    void tellall(void) { cout<<"hell"; }
    ...
};

// 或者
inline void Stock::set_tot()
{
    cout << "hell0";
}
```

内联方法：

定义位于类声明中的函数都将自动成为内联函数，比如 `tellall` ，也可以在类外定义内联函数

内敛函数要求在每个使用他们的文件中都对其进行定义，所以最好定义在类头文件中

### 10.3 构造函数和析构函数

C++ 目标之一就是让使用类对象就像使用标准类型一样。

像初始化结构一样去初始化符合数据隐藏（数据为私有成员）特性的类的数据成员是不行的，因为必须通过成员函数来访问数据成员。如果违背数据隐藏的初衷，那么也是可以初始化的。

#### 使用构造函数

- 显式调用
- 隐式调用

```c
Stock food = Stock("World Cabbage", 250, 1.25);

Stock garment("Furry", 50, 2.5);
// 等价于
Stock garment = Stock("Furry", 50, 2.5);
```

每次创建类对象（甚至使用new动态分配内存）时，C++都使用类构造函数。
```c
Stock *pstock = new Stock("Games", 18, 19.0);
```

#### 默认构造函数

默认构造函数在未提供显示初始值时来创建对象的构造函数
```c
Stock fluffy_the_cat; // 使用默认构造函数
```

注意：
> 当且仅当没有定义任何构造函数时，编译器才会提供默认构造函数。为类定义了构造函数后，就必须为它提供默认构造函数，否则将会出错。

定义默认构造函数的两种方式：
- 给已有构造函数的所有参数提供默认值
- 通过函数重载来定义另一个构造函数——没有参数的构造函数

调用默认构造函数，不进行显示初始化
```c
Stock first;            // 隐式调用默认构造函数
Stock first = Stock();  // 显式调用默认构造函数
Stock *pfirst = new Stock;// 隐式调用
```

注意区分以下情况：
```c
Stock first("name");    // 构造函数
Stock second;           // 默认构造函数
Stock third();          // 返回 stock 对象的函数
```

#### 析构函数

用构造函数创建对象后，对象过期时，程序将自动调用析构函数完成清理工作。

例如：构造函数用 new 分配内存，析构函数使用 delete 释放内存。 Stock 的构造函数没有使用 new 来分配内存，在这种情况下，只需让编译器生成一个什么也不做的隐式析构函数即可。

**什么时候调用析构函数？？？**

- 静态存储类对象

析构函数将在程序结束时被调用

- 自动类存储对象

析构函数在程序执行完代码块时调用，**调用析构时遵循“栈”的原则，先创建的对象后删除**

- 动态存储类对象

使用 delete 来释放内存时，析构函数被调用

另外，在出现创建临时对象情况中，析构函数在程序结束对该临时变量的使用时调用。


两种初始化对象的方式的区别：
```c
// usestock2.cpp
Stock stock1("NanoSmart", 12, 20.0);
Stock stock2 = Stock("Boffo Objects", 2, 2.0);
```
第二种生成stock2的方式C++编译器可以有两种不同的处理方式（是否产生临时对象）
- 其一，产生和第一种方式一样的行为
- **其二，调用构造函数生成临时变量，并将对象复制到stock2，并在丢弃临时对象时调用析构函数**

所以，下面两条语句有根本性的差别：
```c
Stock stock2 = Stock("Boffo Objects", 2, 2.0);
stock1 = Stock("Nifty Foods", 10, 50.0);    // 使用了临时变量
```

第一句是初始化，可能产生临时变量也可能不产生，第二句是赋值，一定会通过构造函数创建临时变量

使用列表初始化方式创建对象
```c
Stock hot_tip = {"name", 1, 1.0};   // 构造函数
Stock jock{"name"}; // 缺省参数使用默认值
Stock temp{};       // 默认构造函数

Stock(const std::string &co, long n = 0, double pr = 0.0);
```

**只要类方法不修改调用对象，就应将其声明为 const ，const 对象只能调用 const 成员函数**
```c
void show() const;

void Stock::show() const
```

#### 小结

初始化新对象的几种方式：
```c
Bozo(const char *fname, const char *lname);

Bozo bozetta = bozo("Bozetta","Biggenss");
Bozo fufu("Fufu","dweeb");
Bozo *pc = new Bozo("Popo","Le Peu");

// 如果支持 C++ 特性，还可以列表初始化
Bozo bozetta = {"Bozetta","Biggens"};
Bozo fufu{"Fufu", "dweeb"};
Bozo *pc = new Bozo{"Popo","Le Peu"}; 
```

### 10.4 this 指针

**为什么类对象作为参数时可以直接访问私有数据类型，而不需要通过公有成员函数？？？**

this 是指向调用对象的指针， *this 才是对象的别名

### 10.5 对象数组

用构造函数初始化对象数组
```c
Stock stocks[10] = {
    Stock("name", 12.5, 20),    // 构造函数，生成临时对象然后复制到元素中
    Stock();    // 默认构造函数
    // 余下的元素将使用默认构造函数初始化
};
```

### 10.6 类作用域

在类作用域内不能定义 const 常量，但可通过其他方式达到目的

- 创建类内枚举符号常量

枚举并不会成为类的数据成员，所有的对象都不包含枚举
```c
class Bakery
{
private:
    enum {Months = 12};
    double costs[Months];
    ...
}
```

- 使用 static 关键字

常量将与其他静态变量存储在一起，并不是存储在对象中

```c
class Bakery
{
private:
    static const int Months = 12;
    double costs[Months];
    ...
}
```

### 10.7 抽象数据类型

- 数据隐藏
- 公共接口
- 数据类型存储和类设计分离