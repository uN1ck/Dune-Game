#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <string>
#include "iStringable.h"
#include <map>
using namespace std;


class cObject :
	public iStringable
{
//Поля
private:	string name;
private:	string description;

		//Конструкторы
			/*Пустой конструктор объекта*/
public:		cObject();
			/*Конструктор копирования объекта*/
public:		cObject(const cObject &in_object);
			/*Параметрический конструктор обьекта*/
public:		cObject(const string in_name, const string in_description);

		//Деструктор
public:		virtual ~cObject();


//Файловые методы класса
			/*Взятие значений полей из файла с именем this->name*/
public:		virtual map< string, string > *readFile();


//Set-Get методы класса
			/*Задать имя объекта*/
public:		virtual void setName(const string &in_name);
			/*Задать описание обьекта*/
protected:	virtual void setDescription(const string &in_description);
			/*Взять имя объекта*/
public:		string getName()const;
			/*Взять описание обьекта*/
public:		string getDescription()const;
//Интерфейсные методы
			/*Метод приведения типа к строке*/
public:		string toString();


};

