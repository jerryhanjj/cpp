// usertime2.cpp -- using the first draft of the Time class
// compile usetime2.cpp and mytime2.cpp together
#include <iostream>
#include "mytime2.h"
using namespace std;

int main()
{
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing; // 重载 +
    total.Show();
    cout << endl;

    diff = weeding - waxing; // 重载 -
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5; // 重载 * ，注意不能是 1.5*total
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;

    return 0;
}