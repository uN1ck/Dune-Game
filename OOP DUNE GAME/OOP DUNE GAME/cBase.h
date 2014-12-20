#pragma once

#include "cUnit.h"
#include "cObject.h"
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <map>
#include "cGunner.h"
#include "cTanker.h"


//bool compareObjects(cUnit *left, cUnit *right);

class cBase :
	public cUnit
{
protected:	vector<cUnit*>* units;
protected:	map<string, int> counts;

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

public: static void saveBinary(vector<iNetStream *> * value, System::String^ name);
public: static void loadBinary(vector<iNetStream *> * value, System::String^ name);
};

//bool compareObjects(cUnit *left, cUnit *right);