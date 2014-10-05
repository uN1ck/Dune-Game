#include "cObject.h"
#include "cUnit.h"

#include <iostream>
using namespace std;

cObject *object;
cObject *unit;

void showMe(cObject *value)
{
	cUnit *casted = dynamic_cast<cUnit*>(value);
	if (casted)
		cout << "toString: \n" << casted->toString() << endl;
	else
		cout << value->getName() << " " << value->getDescription() << endl;
}

int main()
{
	
	object = new cObject("Object", "Description");
	showMe(object);

	unit = new cUnit(object, 10);
	showMe(unit);

	cObject *declassed = new cObject("Declassed", "Declassed");
	showMe(declassed);

	iClonable *iCln = dynamic_cast<iClonable*>(declassed);
	if (iCln)
	{
		cObject *cln = iCln->clone();
		showMe(cln);
	}
	else
	{
		cout << "Is not a iClonable\n";
	}
	

	iStringable *iStr = dynamic_cast<iStringable*>(declassed);
	if (iStr)
	{
		iStringable *str = iStr;
		cout << str->toString() << endl;
	}
	else
	{
		cout << "Is not a iStringable\n";
	}


	system("pause");
	delete object;
	delete unit;
	delete declassed;


	return 0;
}