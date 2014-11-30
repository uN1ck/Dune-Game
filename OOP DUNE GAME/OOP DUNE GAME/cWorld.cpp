#include "cWorld.h"


cWorld::cWorld()
{
	units = vector< cObject& >(0);
	bases = vector< cObject& >(0);
	height = 0;
	width = 0;
	world = vector< vector< cObject* > >(0, vector< cObject* >(0));
}
cWorld::cWorld(const cWorld& value)
{
	units = value.units;
	bases = value.bases;
	height = value.height;
	width = value.height;
	world = value.world;
}

vector< vector< cObject* > > & cWorld::getWorld()
{
	return world;
}
vector< cObject& >	cWorld::getUnits() const
{
	return units;
}

vector< cObject& >	cWorld::getBases() const
{
	return bases;
}
string cWorld::toString()
{
	string result;
	for each(cObject current in bases)
		result += current.toString();
	for each(cObject current in units)
		result += current.toString();
}

void cWorld::setID()
{
	this->ID = typeid(this).name();
}
int cWorld::getHeight()
{
	return height;
}
int cWorld::getHeight()
{
	return height;
}
cWorld::~cWorld()
{
}
