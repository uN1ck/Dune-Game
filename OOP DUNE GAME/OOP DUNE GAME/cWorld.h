#pragma once
#include "cObject.h"
#include "cCell.h"
#include <map>
#include <cmath>

class cWorld :
	public cObject
{
private: vector< vector< cCell* > > world;
private: vector< cUnit& > enities;
		
public:		cWorld();
public:		cWorld(const cWorld &value);
public:		cWorld(const cObject &value, vector< vector< cCell* > > in_world);
	virtual ~cWorld();
};

