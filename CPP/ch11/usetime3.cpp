// usetime3.cpp -- using the fourth draft of the Time class
// compile usetime3.cpp and mytime3.h together
#include <iostream>
#include "mytime3.h"
using namespace std;

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0*tosca << endl;

    return 0;
}