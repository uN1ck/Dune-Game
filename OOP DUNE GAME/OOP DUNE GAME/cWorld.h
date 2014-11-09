#pragma once
#include "cObject.h"
#include <vector>

class cWorld :
	public cObject
{
private:
	vector<vector< cObject& > > grid;


public:
	cWorld();
	virtual ~cWorld();
};

