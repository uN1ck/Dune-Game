#include "cGunControl.h"

cGunControl::cGunControl()
{

}

void cGunControl::activity(cObject* in_world, cObject* in_handler)
{
	iAccess *world = dynamic_cast<iAccess*>(in_world);
	cGunner *self = dynamic_cast<cGunner*>(in_handler);

	if (world && self)
	{
		/*выстрел*/
		vector<cObject*> rounds = world->getAround(self->X(), self->Y(), self->getGun()->getDistance());
		if (rounds.size())
			for (vector<cObject*>::iterator i = rounds.begin(); i != rounds.end(); i++)
				if (dynamic_cast<cUnit*> (*i))
				{
					self->doAction(world, *i);
					break;
				}
		/*Передвижение*/
		switch (rand() % 4)
		{
		case 0:		self->moveDown(world); break;
		case 1:		self->moveLeft(world); break;
		case 2:		self->moveUp(world); break;
		case 3:		self->moveRight(world); break;
		}
	}
}

cGunControl::~cGunControl()
{

}
