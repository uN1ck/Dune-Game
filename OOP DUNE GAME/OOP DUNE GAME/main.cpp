#include <iostream>
#include "cBase.h"

using namespace std;

cBase *first, *second;

int main()
{
	first = new cBase();
	cout << first->toString();


	system("pause");


	return 0;
}