#include "cTanker.h"

cTank* cTanker::getTank()const
{
	return this->tank;
}
void cTanker::setTank(cTank *value)
{
	this->tank = value;
}

cTanker::cTanker() : cUnit(cPosited( cObject("Standart Tanker", "Standart tanker, flying then doesn't mine spice"),0,0), 10)
{
	this->tank = new cTank(cObject("Standart Tank", "Standart Tank with spice"), 0, 100);
	this->setID();
	this->control = new cTankControl();
}
cTanker::cTanker(const cUnit &value, cTank *in_tank) : cUnit(value)
{
	this->setTank(in_tank);
	this->setID();
	this->control = new cTankControl();
}			
cTanker::cTanker(const cTanker &value) : cUnit(value)
{
	this->setTank(value.getTank());
	this->setID();
	this->control = new cTankControl();
}

cTanker::~cTanker()
{
	delete this->tank;
}

void cTanker::Update(cObject *cell, cObject *world)
{
	cUnit::Update(cell, world);
	this->control->activity(world, this);
	/*Место обработки спайса*/
	/*Место отработки интелекта*/
}
void cTanker::setID()
{
	this->ID = typeid(this).name();
}
string cTanker::toString()
{
	string res = cUnit::toString();
	res += this->tank->toString();
	return res;
}