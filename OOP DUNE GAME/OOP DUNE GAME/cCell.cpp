#include "cCell.h"

bool cCell::putUnit( cUnit *unit) 
{
	if (!this->getUnit())
	{
		this->unit = unit;
		return true;
	}
	return false;
}
void  cCell::setUnit(cUnit *unit)
{
	this->unit = unit;
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

vector<cObject*>& cCell::getDeckLink()
{
	return this->deck;
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
	for (int i = 0; i < this->getDeck().size(); i++)
		res = res + " Loot list item -> " + this->getDeck()[i]->toString();
	return res;
}
map< string, string >* cCell::readFile()
{
	map< string, string > *file = cObject::readFile();

	return file;
}

void cCell::Update()
{
	
}

void cCell::generate(int rockChance, int rockRand, int spiceConut)
{
	if (rand() % rockRand < rockChance)
	{
		this->isRock = 1;
		this->setDescription(this->getDescription() + ", contains Rock");
	}
	else
	{
		this->isRock = 1;
		this->setDescription(this->getDescription() + ", does not contains Rock");
	}
	this->setSpice(new cTank(cObject("The spicefield", "Spicefield with some spice inside"), rand() % spiceCount, spiceCount));
}

cCell::cCell(): cObject()
{
	this->isRock = NULL;
	unit = NULL;
	deck = vector<cObject*>(NULL);
	spice = NULL;
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
