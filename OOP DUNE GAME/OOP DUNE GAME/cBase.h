#include "cUnit.h"
#include "cObject.h"
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <map>
#pragma once

bool compareObjects(cUnit *left, cUnit *right);

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

public:		virtual void deleteUnitbyName(string value);
public:		virtual void deleteUnitbyType(string value);

public:		void countStats();
public:		string getStats();

public:		virtual ~cBase();
protected:	virtual void setID();
};

//bool compareObjects(cUnit *left, cUnit *right);