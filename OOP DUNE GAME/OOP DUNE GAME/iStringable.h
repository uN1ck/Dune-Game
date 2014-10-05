#pragma once
#include <string>
#include <sstream>
/*Интерфейс приведения класса к строке*/
class iStringable
{
/*Метод преобразования класска к строке*/
public:		virtual std::string toString() = 0;
};

