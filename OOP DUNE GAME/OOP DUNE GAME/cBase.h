#pragma once

#include "cUnit.h"
#include "cObject.h"
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <map>
#include "cGunner.h"
#include "cTanker.h"
#include "iAccess.h"
#include <set>
#include "iDelete.h"

//bool compareObjects(cUnit *left, cUnit *right);

class cBase :
	public cUnit,
	public iAccess,
	public iDelete
{
protected:	vector<cUnit*>* units;
protected:	map<string, int> counts;
protected:	cTank* supply;
private:	set<string> uniq;

	//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cBase();
			/*Конструктор с параметрами*/
public:		cBase(const cUnit &value, vector<cUnit*>*in_units);
			/*Конструктор копирования*/
public:		cBase(const cBase &value);
	
public:		vector<cUnit*>* getAllUnits() const;
public:		virtual void setAllUnits(vector<cUnit*>* value);
public:		void putUnit(cUnit* value);
public:		void sortAllUnits();
public:		virtual string toString();
public:		virtual cObject* clone();
public:		virtual map< string, string > *readFile();
public:		virtual void Update(cObject *cell, cObject *world);

public:		virtual void Generate(cObject *world, string value);

public:		virtual void deleteUnitbyName(string value);
public:		virtual void deleteUnitbyUN(string value);

public:		void countStats();
public:		string getStats();

public:		virtual ~cBase();
protected:	virtual void setID();

public:		virtual void moveUp(iAccess * world);
public:		virtual void moveDown(iAccess * world);
public:		virtual void moveLeft(iAccess *world);
public:		virtual void moveRight(iAccess *world);
public:		virtual void doAction(iAccess *world, cObject *commited);

protected:	string uniqnameGenerate() const;
public:		virtual cObject* at(int x, int y);
public:		virtual cObject* at(pair<int, int>);
public:		virtual pair<int, int> position(string value);

public:		virtual vector<cObject*> getAround(int x, int y, int r);
};

//bool compareObjects(cUnit *left, cUnit *right);