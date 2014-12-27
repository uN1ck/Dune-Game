#pragma once
#include "iController.h"
#include "cGunner.h"
#include "iAccess.h"

class cGunControl :
	public iController
{
public:
	cGunControl();

	virtual void activity(cObject* in_world, cObject* in_handler);

	virtual ~cGunControl();
};

