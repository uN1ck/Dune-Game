#pragma once
#include <string>
#include "cObject.h"
/*»нтерфейс клонировани€ класса*/
class iClonable
{
	/*ћетод клонирован€и класса в тип ќбьект*/
public:		virtual cObject* clone() = 0;
};

