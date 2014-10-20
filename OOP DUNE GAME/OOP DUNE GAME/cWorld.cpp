#include "cWorld.h"

cWorld::cWorld() :cObject("Random world", "Random-generated world")
{
	this->generate(50, 50);
}
cWorld::cWorld(const cWorld &value) : cObject(value)
{
	this->world = value.getWorld();
}
cWorld::cWorld(const cObject &value, vector< vector< cCell* > > in_world) : cObject(value)
{
	this->world = in_world;
}
cWorld::~cWorld()
{
	for (int i = 0; i < this->world.size(); i++)
		for (int k = 0; k < this->world[i].size(); k++)
			delete world[i][k];
}
