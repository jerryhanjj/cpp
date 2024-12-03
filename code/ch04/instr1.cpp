// instr1.cpp -- reading more than one string 
// page 77
/*
如果在输入name时输入 jerry han，由于cin限制
name为jerry，把 han 残留在输入流中，并在下次 cin 读取时存到 dessert 中
*/
#include <iostream>
using namespace std;

int main()
{
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    return 0;
}