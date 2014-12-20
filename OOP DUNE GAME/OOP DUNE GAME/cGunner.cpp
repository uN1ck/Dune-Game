#include "cGunner.h"


cGun *cGunner::getGun() const
{
	return this->gun  ;
}
void cGunner::setGun(cGun *value)
{
	this->gun = value;
}

cGunner::cGunner() : cUnit(cObject("Standart Gunner", "Standart gunner"), 10)
{
	this->gun = new cGun(cObject("Standart Gunner", "Standart Gunner with gun"),0,1);
	this->setID();
}
cGunner::cGunner(const cUnit &value, cGun *in_gun) : cUnit(value)
{
	this->setGun(in_gun);
	this->setID();
}
cGunner::cGunner(const cGunner &value) : cUnit(value)
{
	this->setGun(value.getGun());
	this->setID();
}

cGunner::~cGunner()
{
	delete this->gun;
}
void cGunner::Update(cObject *cell, cObject *world)
{
	/*Место для стрельбы*/
	/*Место отработки интелекта*/
}
void cGunner::setID()
{
	this->ID = typeid(this).name();
}
string cGunner::toString()
{
	string res = cUnit::toString();
	res += this->gun->toString();
	return res;
}

void cGunner::doAction(iAccess *world, cObject *commited)
{
	cUnit *value = dynamic_cast<cUnit *>(commited);
	if (value)
	{
		value->setArmor(value->getArmor() - this->getGun()->getDamage());
	}
}