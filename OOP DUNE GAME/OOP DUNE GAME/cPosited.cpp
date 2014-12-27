#include "cPosited.h"


cPosited::cPosited() :cObject()
{
	x = 0; 
	y = 0;
}
cPosited::cPosited(const cPosited& value) : cObject(value)
{
	this->X(value.X());
	this->Y(value.Y());
}
cPosited::cPosited(cObject& value, int x, int y) : cObject(value)
{
	this->X(x);
	this->Y(y);
}

int cPosited::X() const
{
	return this->x;
}
int cPosited::Y() const
{
	return this->y;
}

void cPosited::X(int value)
{
	this->x = value;
}
void cPosited::Y(int value)
{
	this->y = value;
}


string cPosited::toString()
{
	return cObject::toString() + "#X " + to_string(this->X()) + "\n#Y " + to_string(this->Y()) + "\n";
}

cPosited::~cPosited()
{
}
