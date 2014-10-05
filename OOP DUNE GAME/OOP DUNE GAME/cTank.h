#pragma once
#include "cObject.h"
class cTank :
	public cObject
{
private:	int filling;
private:	int size;
public:
	cTank();
	virtual ~cTank();
};

