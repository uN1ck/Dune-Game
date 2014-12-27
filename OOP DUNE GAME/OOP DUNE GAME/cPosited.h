#pragma once
#include "cObject.h"
class cPosited :
	public cObject
{
private: int x;
private: int y;

public:		cPosited();
public:		cPosited(const cPosited& value);
public:		cPosited(cObject& value, int x, int y);

public:		virtual int X() const;
public:		virtual int Y() const;
public:		virtual void X(int value);
public:		virtual void Y(int value);

public:		virtual string toString();

virtual ~cPosited();
};

