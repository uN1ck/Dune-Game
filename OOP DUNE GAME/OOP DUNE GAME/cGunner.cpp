#include "cGunner.h"


cGun *cGunner::getGun() const
{
	return this->gun  ;
}
void cGunner::setGun(cGun *value)
{
	this->gun = value;
}

cGunner::cGunner() : cUnit(cObject("Standart Gunner", "Standart gunner without any upgrades"), 10)
{
	this->gun = new cGun(cObject("Standart Gunner", "Standart Gunner with gun"),0,1);
}
cGunner::cGunner(const cUnit &value, cGun *in_gun) : cUnit(value)
{
	this->setGun(in_gun);
}
cGunner::cGunner(const cGunner &value) : cUnit(value)
{
	this->setGun(value.getGun());
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