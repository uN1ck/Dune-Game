#pragma once
#include "cObject.h"

class cTank :
	public cObject
{
	//Поля
private:	int filling;
private:	int size;

	//Конструкторы
			/*Конструктор объекта по умолчанию*/
public:		cTank();
			/*Конструктор копирования объекта*/
public:		cTank(const cTank& value);
			/*Конструктор с параметрами <cObject, текущая наполненность, текущий размер>*/
public:		cTank(const cObject *value, int in_filling, int in_size);
	//Деструктор
public:		virtual ~cTank();

	//Set-Get методы класса
			/*Задать текущую наполненность*/
public:		virtual void setFilling(int value);
			/*Взять текущую наполненность*/
public:		int getFilling() const;

			/*Задать максимальный размер*/
public:		virtual void setSize(int value);
			/*Взять максимальный размер*/
public:		int getSize() const;

	//Перегрузки операторов
			/*Перегрузка оператора сложения, цели испольхования 1) слив двух баков в один*/
public:		friend cTank* operator+(const cTank& left, const cTank& right);
			/*Оператор присвоения*/
public:		virtual cTank* operator=(const cTank &value);

	//Перегруженные методы от наследника
			/*Чтение параметров цистерны с файла*/
public:		virtual map< string, string > *readFile();
			/*Метод приведения класса к строке*/
public:		virtual string toString();

};

