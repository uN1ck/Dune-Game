#pragma once
#include "cObject.h"
#include "iClonable.h"
#include "iUpdateble.h"
#include <SFML/Graphics.hpp>
#include "iMovable.h"
#include "iAccess.h"
#include "iDrawable.h"

class cUnit :
	public cObject,
	public iClonable,
	public iUpdateble,
	public iMovable,
	public iDrawable
{
	//����
private:	bool isFlying;
private:	int armor;
private:	int cost;

private:	sf::Texture texture;
private:	sf::Sprite sprite;
private:	sf::IntRect rectangle;

	//������������
			/*����������� ������� �� ���������*/
public:		cUnit();
			/*����������� cUnit � ����������� <������� �����, �����>*/
public:		cUnit(const cObject &value, int armor_value);
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


//public:		virtual void loadTexture();
//public:		sf::Sprite getSprite() const;

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

			//���������� � �����
public:		virtual void saveToStream(BinaryWriter ^ value);
			//�������� �� ������
public:		virtual void loadFromStream(BinaryReader ^ value);

public:		virtual sf::Sprite getSprite();
public:		virtual sf::Texture getTexture();
public:		virtual sf::IntRect getTextureRectangle();
public:		virtual void setSprite(sf::Sprite);
public:		virtual void setTexture(sf::Texture);
public:		virtual void setTextureRectangle(sf::IntRect);

public:		virtual void moveUp(iAccess * world);
public:		virtual void moveDown(iAccess * world);
public:		virtual void moveLeft(iAccess *world);
public:		virtual void moveRight(iAccess *world);
public:		virtual void doAction(iAccess *world, cObject *commited);

public:		virtual void loadGraphical();
};

