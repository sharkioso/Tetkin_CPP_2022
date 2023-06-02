#include <iostream>
#include "List.h"
int main()
{
	List test;
	test.Add(1);
	test.Add(2);
	test.Add(3);
	test.Add(4);
	cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] <</* " " << test[4] <<*/ endl;
	test.AddIndex(4, 16);
	cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] << " " << test[4] << endl;
	test.Del();
	cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] << endl;
	test.DelIndex(1);
	cout << test[0] << " " << test[1] << " " << test[2] << endl;
}
