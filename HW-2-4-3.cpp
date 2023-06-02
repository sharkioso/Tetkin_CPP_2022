#include "LinkedQueue.h"
#include <iostream>

int main()
{
    LinkedQueue test;
    for (int i = 0; i <= 5; i++)
    {
        test.enqueue(i);
    }
    test.Print();
    test.dequeue();
    test.dequeue();
    int chek = test.getFirst();
    test.Print();
    cout << chek << endl;
}
