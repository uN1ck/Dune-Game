#pragma once
#include "cObject.h"
#include "cUnit.h"
#include "cTank.h"
#include "iUpdateble.h"
#include <vector>

class cCell :
	public cObject,
	public iUpdateble
{
		/*Поля*/
			//Дек предметов в клетке
private:	vector<cObject*> deck;
			//Юнит в клетке
private:	cUnit* unit; //??
			//Спайсовое поле
private:	cTank* spice;
private:	bool isRock;

		/*Set-Get методы*/
			//Задать дек обьектов
protected:	virtual void setDeck(vector<cObject*> value);
			//Взять дек обьектов
public:		vector<cObject*> getDeck()const;
			//Взять ссылку на дек обьектов
public:		virtual vector<cObject*>& getDeckLink();
			//Взять текущего юнита
public:		cUnit* getUnit()const;
			//Уствновить (если нет юнита) текущего юнита
public:		bool putUnit(cUnit *unit);
			//Задать юнита
public:		void setUnit(cUnit *unit);
			//Забрать юнита
public:		cUnit* pickUnit();
			//Взять текущий резервуар спайса
public:		cTank* getSpice()const;
			//Задать текущий резервуар спайса
public:		void setSpice(cTank* value) const;

public:		void generate(int rockChance, int rockRand, int spiceConut);

			//Прочитать текстовый файл
public:		virtual map< string, string > *readFile();
			//Вывести в строку
public:		virtual string toString();
			//Метод обновления клетки
public:		virtual void Update();

			//Конструкоры
public:		cCell();
public:		cCell(const cCell &value);
public:		cCell(const cCell &value, vector<cObject*> in_deck, cUnit *in_unit);
public:		virtual ~cCell();
};

