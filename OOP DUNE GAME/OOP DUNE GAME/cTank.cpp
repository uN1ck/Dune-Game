#include "cTank.h"


cTank::cTank() : cObject()
{
	this->setFilling(0);
	this->setSize(10);
}
cTank::cTank(const cTank& value) : cObject(value)
{
	this->setSize(value.getSize());
	this->setFilling(value.getFilling());
}
cTank::cTank(const cObject *value, int in_filling, int in_size) : cObject(*value)
{
	this->setSize(in_size);
	this->setFilling(in_filling);
}

void cTank::setFilling(int value)
{
	this->filling = ((value > this->size)? size:value);
}
int cTank::getFilling() const
{
	return this->filling;
}

void cTank::setSize(int value)
{
	this->size = value;
}
int cTank::getSize() const
{
	return this->size;
}

map <string, string> *cTank::readFile()
{
	map <string, string> * file = ((cObject*)this)->readFile();
	this->setSize(atoi(file->find("#TankSize")->second.c_str()));
	this->setFilling(atoi(file->find("#TankFilling")->second.c_str()));
	return file;
}

const cTank* operator+(const cTank& left, const cTank& right)
{
	return new cTank(&left, left.getFilling()+right.getFilling(), left.getSize());
}

cTank::~cTank()
{
}
