#pragma once
#include "cObject.h"
#include <vector>
#include "cBase.h"

using namespace std;

class cWorld : 
	public cObject
{
private:	vector< cObject* > *units;
private:	vector< cObject* > *bases;
private:	int height;
private:	int width;
private:	vector< vector< cObject* > > *world;

public:		cWorld();
public:		cWorld(const cWorld& value);

public:	vector< vector< cObject* > > * getWorld();
public: vector< cObject* > *getUnits() const;
public: vector< cObject* > *getBases() const;
public: void putUnit(cUnit* value);
public:	int getHeight();
public: void setHeight(int value);
public:	int getWidth();
public: void setWidth(int value);

public:	virtual void Update();

public:	void Generate(string value);
public: virtual string toString();
protected:	virtual void setID();

public:		virtual map< string, string > *readFile();

	virtual ~cWorld();
};

