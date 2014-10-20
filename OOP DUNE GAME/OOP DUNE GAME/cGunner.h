#pragma once
#include "cUnit.h"
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
			 /*Взять ссылку на оружие*/
public:		 cGun& getGunLink();

	//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cGunner();
			/*Конструктор cUnit с параметрами <Базовый класс, броня>*/
public:		cGunner(const cGunner &value, const cGun &in_gun);
			/*Конструктор копирования*/
public:		cGunner(const cGunner &value);

public:		~cGunner();
};

