#include "cTankControl.h"


cTankControl::cTankControl()
{
}

void cTankControl::activity(cObject* in_world, cObject* in_handler)
{
	iAccess *world = dynamic_cast<iAccess*>(in_world);
	cTanker *self = dynamic_cast<cTanker*>(in_handler);

	if (world && self)
	{
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

cTankControl::~cTankControl()
{
}
