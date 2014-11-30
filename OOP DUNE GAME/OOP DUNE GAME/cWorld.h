#pragma once
#include "cObject.h"
#include "vector"

using namespace std;

class cWorld : 
	public cObject
{
private:	vector< cObject& > units;
private:	vector< cObject& > bases;
private:	int height;
private:	int width;
private:	vector< vector< cObject* > > world;

public:
	

	cWorld();
	cWorld(const cWorld& value);

public:	vector< vector< cObject* > > &getWorld();
public: vector< cObject& >	getUnits() const;
public: vector< cObject& >	getBases() const;
public:	int getHeight();
public: void setHeight(int value);
public:	int getWidth();
public: void setWidth(int value);

public:	void Generate();
public: virtual string toString();
protected:	virtual void setID();
	virtual ~cWorld();
};

