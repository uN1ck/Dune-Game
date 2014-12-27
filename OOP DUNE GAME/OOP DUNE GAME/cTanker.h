#pragma once
#include "cUnit.h"
#include "cTank.h"
#include "cTankControl.h"

class cTanker :
	public cUnit
{
	/*Поля*/
			 /*полес цистерной спайса*/
private:	 cTank *tank;

			 /*Взять цистерну*/
public:		 cTank* getTank() const;
			 /*Задать цистерну*/
public:		 void setTank(cTank *value);

	/*Конструктор объекта по умолчанию*/
public:		cTanker();
			/*Конструктор cUnit с параметрами <Базовый класс, броня>*/
public:		cTanker(const cUnit &value,cTank *in_tank);
			/*Конструктор копирования*/
public:		cTanker(const cTanker &value);

public:		virtual void Update(cObject *cell, cObject *world);

public:		virtual~cTanker();
protected:	virtual void setID();

public:		virtual string toString();

};

