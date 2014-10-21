#pragma once
#include "cCell.h"
#include "cWorld.h"

/*Интерфейс обновляемого класса*/
class iUpdateble
{
/*Метод обновления класса*/
public:		virtual void Update(cCell *cell_value, cWorld *world_value) = 0;
};