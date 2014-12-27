#pragma once
#include "cObject.h"
#include <vector>
#include "iUpdateble.h"
#include "iAccess.h"
#include <set>
#include "cBase.h"
#include "cPosited.h"


using namespace std;

class cWorld : 
	public cObject,
	public iAccess
{
private:	vector< cObject* > *units;
private:	vector< cObject* > *bases;
private:	int height;
private:	int width;

public:		cWorld();
public:		cWorld(const cWorld& value);

public:	vector< vector< cObject* > > * getWorld();
public: vector< cObject* > *getUnits() const;
public: vector< cObject* > *getBases() const;

public:	virtual cObject* at(int x, int y);
public:	virtual cObject* at(pair<int, int>);
public:	virtual pair<int, int> position(string value);

public: void putUnit(cObject* value);
public:	int getHeight();
public: void setHeight(int value);
public:	int getWidth();
public: void setWidth(int value);

public:	virtual void Update();

public:	void Generate(string value, bool debug = 0);
public: virtual string toString();
protected:	virtual void setID();

public:		virtual map< string, string > *readFile();

public:		static string generateSEED();

public:		virtual vector<cObject*> getAround(int x, int y, int r);
	virtual ~cWorld();
};

