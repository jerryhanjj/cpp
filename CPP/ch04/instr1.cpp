// instr1.cpp -- reading more than one string 
// page 77
/*
���������nameʱ���� jerry han������cin����
nameΪjerry���� han �������������У������´� cin ��ȡʱ�浽 dessert ��
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