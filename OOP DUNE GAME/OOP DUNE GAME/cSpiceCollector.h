#pragma once
#include "cUnit.h"
#include "cTank.h"

class cSpiceCollector :
	public cUnit
{
	/*Поля*/
			 /*полес цистерной спайса*/
private:	 cTank *tank;

			 /*Взять цистерну*/
public:		 cTank* getTank() const;
			 /*Задать цистерну*/
public:		 void setTank(cTank *value);
			 /*взять ссылку на цистерну*/
public:		 cTank& getTankLink();

	/*Конструктор объекта по умолчанию*/
public:		cSpiceCollector();
			/*Конструктор cUnit с параметрами <Базовый класс, броня>*/
public:		cSpiceCollector(const cUnit &value, const cTank &in_tank);
			/*Конструктор копирования*/
public:		cSpiceCollector(const cSpiceCollector &value);

	
	~cSpiceCollector();
};

