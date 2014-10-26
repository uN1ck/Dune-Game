#pragma once
#include "cObject.h"
/*Интерфейс обновляемого класса*/
class iUpdateble
{
/*Метод обновления класса*/
public:		virtual void Update(cObject *base, cObject *world) = 0;
};