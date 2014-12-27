#pragma once
#include "cPosited.h"
#include "iClonable.h"
#include "iUpdateble.h"
#include <SFML/Graphics.hpp>
#include "iMovable.h"
#include "iAccess.h"
#include "iDrawable.h"
#include "iController.h"

class cUnit :
	public cPosited,
	public iClonable,
	public iUpdateble,
	public iMovable
{
	//Поля
private:	bool isFlying;
private:	int armor;
private:	int cost;
protected:	iController *control;


	//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cUnit();
			/*Конструктор cUnit с параметрами <Базовый класс, броня>*/
public:		cUnit(const cPosited &value, int armor_value);
			/*Конструктор копирования*/
public:		cUnit(const cUnit &value);
	//Деструктор
public:		virtual ~cUnit();

	//Set-Get методы класса
			/*Определяет находится ли обьект в воздухе*/
public:		bool getFlying() const;
			/*Взять текущее значение брони*/
public:		int	getArmor() const;

public:		int getCost();
public:		virtual void setCost(int value);

			/*Задать нахождени еобьекта в воздухе или на земле*/
public:		virtual void setFlying(bool value);
			/*Задать абсолютное значение брони*/
public:		virtual void setArmor(int value);

	//  Интерфейсные методы
			//Приведенеи к строке
public:		virtual string toString();
			//Клонирование
public:		virtual cObject* clone();
	// Перегруженные от наследника методы
			/*Чтение параметров {armor и предка} из файла*/
public:		virtual map< string, string > *readFile();
public:		virtual void Update(cObject *cell, cObject *world);
protected:	virtual void setID();



public:		virtual void moveUp(iAccess * world);
public:		virtual void moveDown(iAccess * world);
public:		virtual void moveLeft(iAccess *world);
public:		virtual void moveRight(iAccess *world);
public:		virtual void doAction(iAccess *world, cObject *commited);


};

