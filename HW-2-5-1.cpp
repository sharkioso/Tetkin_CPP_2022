#include <iostream>
#include "RationalNumber.h"
using namespace std;
int main()
{
    RationalNumbers chek(5,15);
    RationalNumbers test(10, 15);
    chek - test;
    chek.reduction();
    chek.Print();
    cout << (chek < test) << endl;
}

