#include "cUnit.h"

//Set-Get методы класса
bool	cUnit::getFlying() const
{
	return isFlying;
}
int		cUnit::getArmor() const
{
	return armor;
}

void cUnit::setFlying(bool value)
{
	this->isFlying = value;
}
void cUnit::setArmor(int value)
{
	this->armor = value;
}

map <string, string> *cUnit::readFile()
{
	map <string, string> * file = ((cObject*)this)->readFile();
	this->setName(file->find("#Armor")->second);
	return file;
}

cUnit::cUnit() : cObject()
{
	this->setArmor(5);
	this->setID();
}
cUnit::cUnit(const cObject& value, int armor_value) : cObject(value)
{
	this->setArmor(armor_value);
	this->setID();
}
cUnit::cUnit(const cUnit &value) : cObject(value)
{
	this->setArmor(value.getArmor());
	this->setID();
}

void cUnit::Update(cObject *cell, cObject *world)
{

}

cUnit::~cUnit()
{
}

string cUnit::toString()
{
	return cObject::toString() + "#Armor " + to_string(this->getArmor()) + "\n";
}
cObject* cUnit::clone()
{
	cObject *cloned = new cUnit(*this);
	return cloned;
}

void cUnit::setCost(int value)
{
	this->cost = value;
}
int cUnit::getCost()
{
	return this->cost;
}

void cUnit::setID()
{
	this->ID = typeid(this).name();
}


void cUnit::saveToStream(BinaryWriter ^ value){
	try{
		cObject::saveToStream(value);
		value->Write(this->getArmor());
		value->Write(this->getCost());
	}
	catch (System::Exception^ e)
	{
		throw e;
	}
}

void cUnit::loadFromStream(BinaryReader ^ value){
	try{
		cObject::loadFromStream(value);
		this->setArmor(value->ReadInt32());
		this->setCost(value->ReadInt32());
		this->setID();
	}
	catch (System::Exception^ e)
	{
		throw e;
	}
};

sf::Sprite  cUnit::getSprite()
{
	return this->sprite;
}
sf::Texture cUnit::getTexture()
{
	return this->texture;
}
sf::IntRect cUnit::getTextureRectangle()
{
	return this->rectangle;
}
void cUnit::setSprite(sf::Sprite value)
{
	this->sprite = value;
}
void cUnit::setTexture(sf::Texture value)
{
	this->texture = value;
}
void cUnit::setTextureRectangle(sf::IntRect value)
{
	this->rectangle = value;
}

void cUnit::moveUp(iAccess * world)
{
}
void cUnit::moveDown(iAccess * world)
{

}
void cUnit::moveLeft(iAccess * world)
{

}
void cUnit::moveRight(iAccess * world)
{

}
void cUnit::doAction(iAccess *world, cObject *commited)
{

}