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
	return cObject::toString() + "#Armor " + to_string(this->getArmor()) + "\n#ID |" + this->getID() + "|\n";
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

int cUnit::getX()
{
	return x;
}
int cUnit::getY()
{
	return y;
}
void cUnit::setX(int value)
{
	x = value;
}
void cUnit::setY(int value)
{
	y = value;
}

void cUnit::saveToStream(BinaryWriter ^ value){
	cObject::saveToStream(value);
	value->Write(this->getArmor());
	value->Write(this->getCost());
	value->Write(this->getX());
	value->Write(this->getY());
}

void cUnit::loadFromStream(BinaryReader ^ value){

	cObject::loadFromStream(value);
	this->setArmor(value->ReadInt32());
	this->setCost(value->ReadInt32());
	this->setX(value->ReadInt32());
	this->setY(value->ReadInt32());	
	this->setID();
};

/*void cUnit::loadTexture()
{
	this->texture.loadFromFile(this->getName());
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 255));
}
sf::Sprite cUnit::getSprite() const
{
	return sprite;
}*/