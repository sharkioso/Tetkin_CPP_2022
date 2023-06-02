#include "LinkedStack.h"
#include <iostream>

int main()
{
    stak test;
    for (int i = 0; i <= 5; i++) {
        test.push(i);
    }
    test.Print();
    test.pop();
    test.pop();
    test.Print();
    int chek = test.getTop();
    test.Print();
    cout << chek << endl;
}
