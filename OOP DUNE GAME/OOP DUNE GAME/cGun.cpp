#include "cGun.h"

int cGun::getDistance() const
{
	return this->distance;
}
int cGun::getDamage() const
{
	return this->damage;
}

void cGun::setDistance(const int value)
{
	this->distance = value;
}
void cGun::setDamage(const int value)
{
	this->damage;
}

map <string, string> *cGun::readFile()
{
	map <string, string> * file = ((cObject*)this)->readFile();
	this->setName(file->find("#Damage")->second);
	this->setName(file->find("#DamageDistance")->second);
	return file;
}

cGun::cGun() :cObject()
{
	this->setDistance(1);
	this->setDamage(1);
	this->setID();
}
cGun::cGun(const cGun &value) : cObject(value)
{
	this->setDamage(value.getDamage());
	this->setDistance(value.getDistance());
	this->setID();
}
cGun::cGun(const cObject &value, int distance_value, int damage_value) : cObject(value)
{
	this->setDistance(distance_value);
	this->setDamage(damage_value);
	this->setID();
}

cGun::~cGun()
{
}
void cGun::setID()
{
	this->ID = typeid(this).name();
}

string cGun::toString()
{
	string res = cObject::toString();
	res += "#Damage" + to_string(this->getDamage()) + "\n";
	res += "#DamageDistance" + to_string(this->getDistance()) + "\n";
	return res;
}
