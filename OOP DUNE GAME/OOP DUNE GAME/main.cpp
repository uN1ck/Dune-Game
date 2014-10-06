#include "cObject.h"
#include "cUnit.h"
#include "cTank.h"

#include <iostream>
using namespace std;

void showMe(cObject *value)
{
	cUnit *casted = dynamic_cast<cUnit*>(value);
	if (casted)
		cout << "toString: \n" << casted->toString() << endl;
	else
	{
		cTank *casted = dynamic_cast<cTank*>(value);
		if (casted)
			cout << casted->toString() << endl;
		else 
			cout << value->getName() << " " << value->getDescription() << endl;
	}
}

int main()
{
	cObject *o_object = new cObject("default", "");
	o_object->readFile();

	cTank *t_default = new cTank();
	showMe(t_default);
	cTank *t_object = new cTank(o_object, 6, 25);
	showMe(t_object);
	cTank *t_copy = new cTank(*t_default);
	showMe(t_copy);
	t_default = *t_default + *t_object;
	showMe(t_default);
	t_default = t_copy;
	showMe(t_default);

	system("pause");

	return 0;
}