#pragma once
#include "cObject.h"
#include <iostream>

class iAccess
{
public:		virtual cObject* at(int x, int y) = 0;
public:		virtual cObject* at(pair<int, int>) = 0;
public:		virtual pair<int, int> position(string value) = 0;
public:		virtual bool place(cObject* value, pair<int, int>) = 0;
};

