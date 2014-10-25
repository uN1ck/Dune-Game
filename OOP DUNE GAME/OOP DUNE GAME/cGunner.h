#pragma once
#include "cUnit.h"
#include "cCell.h"
#include "cWorld.h"
#include "cGun.h"

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
};

