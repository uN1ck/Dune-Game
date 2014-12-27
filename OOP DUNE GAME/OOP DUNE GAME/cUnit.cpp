#include "cUnit.h"

//Set-Get методы класса
bool	cUnit::getFlying() const
{
	return isFlying;
}
int		cUnit::getArmor() const
{
	return armor;
}

void cUnit::setFlying(bool value)
{
	this->isFlying = value;
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

cUnit::cUnit() : cPosited()
{
	this->control = 0;
	this->setArmor(5);
	this->setID();
}
cUnit::cUnit(const cPosited& value, int armor_value) : cPosited(value)
{
	this->control = 0;
	this->setArmor(armor_value);
	this->setID();
}
cUnit::cUnit(const cUnit &value) : cPosited(value)
{
	this->control = 0;
	this->setArmor(value.getArmor());
	this->setID();
}

void cUnit::Update(cObject *cell, cObject *world)
{
}

cUnit::~cUnit()
{
}

string cUnit::toString()
{
	return cPosited::toString() + "#Armor " + to_string(this->getArmor()) + "\n";
}
cObject* cUnit::clone()
{
	cObject *cloned = new cUnit(*this);
	return cloned;
}

void cUnit::setCost(int value)
{
	this->cost = value;
}
int cUnit::getCost()
{
	return this->cost;
}

void cUnit::setID()
{
	this->ID = typeid(this).name();
}



void cUnit::moveUp(iAccess *world)
{
	if (world->at(this->X(), this->Y() - 1)->getName()=="empty")
		this->Y(this->Y() - 1);
}
void cUnit::moveDown(iAccess * world)
{
	if (world->at(this->X(), this->Y() + 1)->getName() == "empty")
		this->Y(this->Y() + 1);
}
void cUnit::moveLeft(iAccess * world)
{
	if (world->at(this->X() - 1, this->Y())->getName() == "empty")
		this->X(this->X() - 1);
}
void cUnit::moveRight(iAccess * world)
{
	if (world->at(this->X() + 1, this->Y())->getName() == "empty")
		this->X(this->X() + 1);
}
void cUnit::doAction(iAccess *world, cObject *commited)
{

}

