// assgn_st.cpp -- assingning structures
// program 4.12 page 91 �ṹ��ֵ

#include <iostream>
using namespace std;

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    inflatable bouquet =
    {
        "sunflowers",
        0.20f,
        12.49
    };

    inflatable choice;
    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;

    choice = bouquet;
    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;
    return 0;
}