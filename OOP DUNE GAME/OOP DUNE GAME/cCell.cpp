#include "cCell.h"

bool cCell::setUnit(const cUnit *unit) const
{
	if (!this->getUnit())
	{
		this->setUnit(unit);
		return true;
	}
	return false;
}
cUnit* cCell::getUnit()const
{
	return this->unit;
}
cUnit* cCell::pickUnit()
{
	cUnit* res = this->getUnit();
	unit = NULL;
	return res;
}

void cCell::setDeckElement(cObject *value, int index)
{
	if (index < this->deck.size())
		this->deck[index] = value;
	else
		this->deck.push_back(value);
}
cObject* cCell::getDeckElement(const int index) const
{
	if (index < this->deck.size())
		return this->deck[index];
	return NULL;
}

void cCell::setDeck(vector<cObject*> value)
{
	this->deck = value;
}
vector<cObject*> cCell::getDeck()const
{
	return this->deck;
}

string cCell::toString()
{
	string res;
	res = res + cObject::toString() +"Unit:" + ((this->getUnit())? this->getUnit()->toString():"Empty") + this->getSpice()->toString();
	for (int i = 0; i < this->getSize(); i++)
		res = res + " Loot list item -> " + this->getDeckElement(i)->toString();
	return res;
}
map< string, string >* cCell::readFile()
{
	map< string, string > *file = cObject::readFile();
	//Дописать считывание для карты!
	return file;
}

cCell::cCell() : cObject()
{
	unit = (((rand() % 1000) < 100) ? new cUnit(cObject("Rock", "The Rock"), 100000) : NULL);
	deck = vector<cObject*> (0);
	int value = rand()%100;
	spice = new cTank( cObject("Spicefield", "The field with spice"), value, value);
}
cCell::cCell(const cCell &value) : cObject(value)
{
	this->setDeck(value.getDeck());
	this->setUnit(value.getUnit());
}
cCell::cCell(const cCell &value, vector<cObject*> in_deck, cUnit *in_unit) : cObject(value)
{
	this->setDeck(in_deck);
	this->setUnit(in_unit);
}

cCell::~cCell()
{
}
