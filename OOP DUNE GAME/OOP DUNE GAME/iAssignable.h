#pragma once
#include "cObject.h"
/*Интерфейс обновляемого класса*/
class iAssignable
{
	/*Метод обновления класса*/
public:		virtual cObject* operator=(const cObject &value) = 0;
};