#pragma once
#include "cObject.h"
#include <iostream>
#include <vector>

class iAccess
{
public:		virtual cObject* at(int x, int y) = 0;
public:		virtual cObject* at(pair<int, int>) = 0;
public:		virtual pair<int, int> position(string value) = 0;
public:		virtual vector<cObject*> getAround(int x, int y, int r, cObject *base) = 0;
};

