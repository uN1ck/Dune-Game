#pragma once
#include "cObject.h"
/*��������� ������������ ������*/
class iUpdateble
{
/*����� ���������� ������*/
public:		virtual void Update(cObject *world, cObject *base) = 0;
};