#pragma once
#include "cObject.h"
#include "cUnit.h"
#include "cTank.h"
#include <vector>

class cCell :
	public cObject
{
		/*Поля*/
			//Дек предметов в клетке
private:	vector<cObject*> deck;
			//Юнит в клетке
private:	cUnit* unit;
			//Спайсовое поле
private:	cTank* spice;

		/*Set-Get методы*/
			//Взять элемент из дека объектов
public:		cObject* getDeckElement(const int value) const;
			//Взять разсер дека обьектов
public:		int getSize() const;
			//Задать элемент дека
public:		virtual void setDeckElement(cObject *value, int index);
			//Задать дек
protected:	virtual void setDeck(vector<cObject*> value);
			//Взять дек обьектов
public:		vector<cObject*> getDeck()const;

			//Взять текущего юнита
public:		cUnit* getUnit()const;
			//Задать текущего юнита
public:		bool setUnit(const cUnit *unit) const;
public:		cUnit* pickUnit();
			//Взять текущий резервуар спайса
public:		cTank* getSpice()const;
			//Задать текущий резервуар спайса
public:		void setSpice(cTank* value) const;

			//Прочитать текстовый файл
public:		virtual map< string, string > *readFile();
			//Вывести в строку
public:		virtual string toString();

			//Конструкоры
public:		cCell();
public:		cCell(const cCell &value);
public:		cCell(const cCell &value, vector<cObject*> in_deck, cUnit *in_unit);
public:		virtual ~cCell();
};

