#pragma once
#include "cObject.h"
/*Интерфейс обновляемого класса*/
class iUpdateble
{
/*Метод обновления класса*/
public:		virtual void Update(cObject *world, cObject *base) = 0;
};