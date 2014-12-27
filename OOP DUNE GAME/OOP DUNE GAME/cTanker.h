#pragma once
#include "cUnit.h"
#include "cTank.h"
#include "cTankControl.h"

class cTanker :
	public cUnit
{
	/*����*/
			 /*����� ��������� ������*/
private:	 cTank *tank;

			 /*����� ��������*/
public:		 cTank* getTank() const;
			 /*������ ��������*/
public:		 void setTank(cTank *value);

	/*����������� ������� �� ���������*/
public:		cTanker();
			/*����������� cUnit � ����������� <������� �����, �����>*/
public:		cTanker(const cUnit &value,cTank *in_tank);
			/*����������� �����������*/
public:		cTanker(const cTanker &value);

public:		virtual void Update(cObject *cell, cObject *world);

public:		virtual~cTanker();
protected:	virtual void setID();

public:		virtual string toString();

};

