#pragma once
#include "iController.h"
#include "cTanker.h"
#include "iAccess.h"

class cTankControl :
	public iController
{
public:
	cTankControl();

	virtual void activity(cObject* in_world, cObject* in_handler);

	virtual ~cTankControl();
};

