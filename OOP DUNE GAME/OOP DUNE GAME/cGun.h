#pragma once
#include "cObject.h"
#include <map>
#include <string>

class cGun :
	public cObject
{
	//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cGun();
			/*Конструктор копирования объекта*/
public:		cGun(const cGun &value);
public:		cGun(cObject *value, int distance_value, int damage_value);
	//Деструкторы
public:		virtual ~cGun();

	//Поля
private:	int distance;
private:	int damage;
	//Set-Get методы класса
			/*Взять максимальную дистанцию поражения*/
public:		virtual int getDistance() const;
			/*Взять урон*/
public:		virtual int getDamage() const;
			/*Задать максимальную дистацию поражения*/
private:	void setDistance(const int value);
			/*Задать максимальный урон*/
private:	void setDamage(const int value);

	// Перегруженные от наследника методы
			/*Чтение параметров {armor и предка} из файла*/
public:		virtual map< string, string > *readFile();


};

