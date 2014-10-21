#pragma once
#include "cObject.h"
#include "iClonable.h"
#include "iUpdateble.h"
#include "cController.h"

#include <string>
#include <map>

class cUnit :
	public cObject,
	public iClonable,
	public iUpdateble

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
public:		virtual cController* getController()const;
			/*Вернуть ссылку на себя*/
public:		virtual cUnit& getLink();
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
			/*Метод обновления обьекта*/
public:		virtual void Update(cCell *cell_value, cWorld *world_value);

};

