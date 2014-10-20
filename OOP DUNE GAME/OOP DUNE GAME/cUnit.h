#pragma once
#include "cObject.h"
#include "iClonable.h"
#include "iStringable.h"
#include "cController.h"

class cUnit :
	public cObject,
	public iClonable

{
	/*Поля*/
private:	bool isFlying;
private:	int armor;
private:	cController *controller;

	/*Конструкторы*/
			/*Конструктор объекта по умолчанию*/
public:		cUnit();
			/*Конструктор cUnit с параметрами <Базовый класс, броня>*/
public:		cUnit(const cObject &value, int armor_value);
			/*Конструктор копирования*/
public:		cUnit(const cUnit &value);
	/*Деструктор*/
public:		virtual ~cUnit();

	/*Set-Get методы класса*/
			/*Определяет находится ли обьект в воздухе*/
public:		bool getFlying() const;
			/*Взять текущее значение брони*/
public:		int	getArmor() const;

			/*Задать нахождени еобьекта в воздухе или на земле*/
public:		virtual void setFlying(bool value);
			/*Задать абсолютное значение брони*/
public:		virtual void addArmor(int value);
			/*Задать измененение брони*/
private:	void setArmor(int value);
			/*Задать контроллер юнита*/
public:		cController* getController()const;

	/*Интерфейсные методы*/
			//Приведенеи к строке
public:		virtual string toString();
			//Клонирование
public:		virtual cObject* clone();
	/*Перегруженные от наследника методы*/
			/*Чтение параметров {armor и предка} из файла*/
public:		virtual map< string, string > *readFile();
			/*Оператор присвоения*/
public:		virtual cUnit* operator=(const cUnit &value);

};

