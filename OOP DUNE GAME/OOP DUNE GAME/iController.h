#pragma once
#include "cObject.h"

class iController 
{
public:
	virtual void activity(cObject* world, cObject* handler, cObject* base) = 0;
};

