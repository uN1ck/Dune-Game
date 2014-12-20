#pragma once
#include "iAccess.h"

class iMovable
{
public:
	virtual void moveUp(iAccess * world) = 0;
	virtual void moveDown(iAccess * world) = 0;
	virtual void moveLeft(iAccess *world) = 0;
	virtual void moveRight(iAccess *world) = 0;
	virtual void doAction(iAccess *world, cObject *commited) = 0;
};

