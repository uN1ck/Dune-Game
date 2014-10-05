#include "cUnit.h"

//Set-Get методы класса
bool	cUnit::IsFying() const
{
	return isFlying;
}
int		cUnit::getArmor() const
{
	return armor;
}

void cUnit::IsFlying(bool value)
{
	this->isFlying = value;
}
void cUnit::addArmor(int value)
{
	this->armor += value;
}
void cUnit::setArmor(int value)
{
	this->armor = value;
}

map <string, string> *cUnit::readFile()
{
	map <string, string> * file = ((cObject*)this)->readFile();
	this->setName(file->find("#Armor")->second);
	return file;
}

cUnit::cUnit() : cObject()
{
	this->setArmor(5);
}
cUnit::cUnit(cObject* value, int armor_value) : cObject(*value)
{
	this->setArmor(armor_value);
}
cUnit::cUnit(const cUnit &value) : cObject(value)
{
	this->setArmor(value.getArmor());
}

cUnit::~cUnit()
{
}

string cUnit::toString()
{
	return cObject::toString() + "#Armor " + to_string(this->getArmor()) + "\n";
}
cObject* cUnit::clone()
{
	cObject *cloned = new cUnit(*this);
	return cloned;
}