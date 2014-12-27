#pragma once
#include "cUnit.h"
#include "cGun.h"
#include "cGunControl.h"

class cGunner :
	public cUnit
{
	/*Поля*/
			 /*Поле с оружием*/
private:	 cGun* gun;

		/*Set-Get методы*/
			 /*Взять оружие*/
public:		 cGun* getGun() const;
			 /*Задать оружие*/
public:		 void setGun(cGun *value);


	//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cGunner();
			/*Конструктор cUnit с параметрами <Базовый класс, броня>*/
public:		cGunner(const cUnit &value, cGun *in_gun);
			/*Конструктор копирования*/
public:		cGunner(const cGunner &value);

public:		virtual void Update(cObject *cell, cObject *world);

public:		~cGunner();
protected:	virtual void setID();

public:		virtual string toString();

public:		virtual void doAction(iAccess *world, cObject *commited);
};

