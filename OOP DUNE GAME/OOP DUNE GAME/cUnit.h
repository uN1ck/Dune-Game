#pragma once
#include "cPosited.h"
#include "iClonable.h"
#include "iUpdateble.h"
#include <iostream>
#include "iMovable.h"
#include "iAccess.h"
#include "iDrawable.h"
#include "iController.h"
#include "iDelete.h"

class cUnit :
	public cPosited,
	public iClonable,
	public iUpdateble,
	public iMovable
{
	//����
private:	bool isFlying;
private:	int armor;
private:	int cost;
protected:	iController *control;


	//������������
			/*����������� ������� �� ���������*/
public:		cUnit();
			/*����������� cUnit � ����������� <������� �����, �����>*/
public:		cUnit(const cPosited &value, int armor_value);
			/*����������� �����������*/
public:		cUnit(const cUnit &value);
	//����������
public:		virtual ~cUnit();

	//Set-Get ������ ������
			/*���������� ��������� �� ������ � �������*/
public:		bool getFlying() const;
			/*����� ������� �������� �����*/
public:		int	getArmor() const;

public:		int getCost();
public:		virtual void setCost(int value);

			/*������ ��������� �������� � ������� ��� �� �����*/
public:		virtual void setFlying(bool value);
			/*������ ���������� �������� �����*/
public:		virtual void setArmor(int value);

	//  ������������ ������
			//���������� � ������
public:		virtual string toString();
			//������������
public:		virtual cObject* clone();
	// ������������� �� ���������� ������
			/*������ ���������� {armor � ������} �� �����*/
public:		virtual map< string, string > *readFile();
public:		virtual void Update(cObject *cell, cObject *world);
protected:	virtual void setID();

public:		virtual void moveUp(iAccess * world);
public:		virtual void moveDown(iAccess * world);
public:		virtual void moveLeft(iAccess *world);
public:		virtual void moveRight(iAccess *world);
public:		virtual void doAction(iAccess *world, cObject *commited);


};

