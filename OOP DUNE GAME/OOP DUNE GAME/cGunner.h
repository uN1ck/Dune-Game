#pragma once
#include "cUnit.h"
#include "cGun.h"
#include "cGunControl.h"

class cGunner :
	public cUnit
{
	/*����*/
			 /*���� � �������*/
private:	 cGun* gun;

		/*Set-Get ������*/
			 /*����� ������*/
public:		 cGun* getGun() const;
			 /*������ ������*/
public:		 void setGun(cGun *value);


	//������������
			/*����������� ������� �� ���������*/
public:		cGunner();
			/*����������� cUnit � ����������� <������� �����, �����>*/
public:		cGunner(const cUnit &value, cGun *in_gun);
			/*����������� �����������*/
public:		cGunner(const cGunner &value);

public:		virtual void Update(cObject *world, cObject *base);

public:		~cGunner();
protected:	virtual void setID();

public:		virtual string toString();

public:		virtual void doAction(iAccess *world, cObject *commited);
};

