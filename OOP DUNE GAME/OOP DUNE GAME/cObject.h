#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <string>
#include "iStringable.h"
#include <map>
#include "iNetStream.h"

#include <msclr/marshal.h>

using namespace msclr::interop;
using namespace std;
using namespace System::IO;



class cObject :
	public iStringable, public iNetStream
{
//Поля
private:	string name;
private:	string description;
protected:	string ID;
protected:	string uniqueName;

		//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cObject();
			/*Конструктор копирования объекта*/
public:		cObject(const cObject &in_object);
			/*Конструктор с параметрами <имя объекта, описание объекта>*/
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
//Перегрузка оператора присовения
			/*Оператор присвоения*/
public:		virtual cObject* operator=(const cObject &value);

//Интерфейсные методы
			/*Метод приведения типа к строке*/
public:		virtual string toString();

public:		string getID() const;
protected:	virtual void setID();

public:	static string getString(BinaryReader ^value);

		//Сохранение в поток
public:		virtual void saveToStream(BinaryWriter ^ value);
		//Выгрузка из потока
public:		virtual void loadFromStream(BinaryReader ^ value);

public:		virtual string getUN();
public:		virtual void setUN(string value);

};

