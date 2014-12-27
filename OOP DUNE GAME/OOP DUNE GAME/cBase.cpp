#include "cBase.h"

using namespace std;

cBase::cBase() : cUnit(cPosited(cObject("Default base name", "Default Base description"), 0 , 0), 1000)
{
	units = new vector<cUnit*>(0);
	this->setID();
}
cBase::cBase(const cUnit &value, vector<cUnit*>*in_units) : cUnit(value)
{
	this->setAllUnits(in_units);
	this->setID();
}
cBase::cBase(const cBase &value) : cUnit(value)
{
	this->setAllUnits(value.getAllUnits());
	this->setID();
}

bool compareObjects(cUnit *left, cUnit *right)
{
	return left->getID() > right->getID();
}

vector<cUnit*>* cBase::getAllUnits() const
{
	return this->units;
}
void cBase::setAllUnits(vector<cUnit*>* value)
{
	this->units = value;
	for each(cUnit* current in *units)
	{
		this->setCost(this->getCost() + current->getCost());
	}
}

string cBase::toString()
{
	string res = cUnit::toString() + "\n################################\n";
	for each(cUnit* current in *units)
	{
		res += current->toString() + "\n================================\n";
	}
	return res;
}
map< string, string > *cBase::readFile()
{
	map <string, string> * file = ((cUnit*)this)->readFile();
	return file;
}
cObject* cBase::clone()
{
	cObject *cloned = new cBase(*this);
	return cloned;
}
void cBase::Update(cObject *cell, cObject *world)
{
	for each (iUpdateble* current in *units)
	{
		current->Update(this, world);
	}
}
void cBase::putUnit(cUnit* value)
{
	this->units->push_back(value);
	this->setCost(this->getCost() + value->getCost());
	if (this->counts.find(value->getID()) != this->counts.end())
		this->counts[value->getID()]++;
	else
		this->counts.insert(pair<string, int>(value->getID(), 1));
}
void cBase::sortAllUnits()
{
	sort(this->units->begin(), this->units->end(), &compareObjects);
}

cBase::~cBase()
{
	for (vector<cUnit*> ::iterator itr = units->begin(); itr != units->end(); itr++)
		delete *itr;
	delete units;
}

void cBase::countStats()
{
	this->counts.clear();
	for each(cUnit* current in *units)
	{
		if (this->counts.find(current->getID()) != this->counts.end())
			this->counts[current->getID()]++;
		else
			this->counts.insert(pair<string, int>(current->getID(), 1));
	}
}
string cBase::getStats()
{
	string res;
	for each (pair<string, int> current in counts)
	{
		res += "TypeName: " + current.first + " TypeCount: " + to_string(current.second) + "\n";
	}
	return res;
}


void cBase::setID()
{
	this->ID = typeid(this).name();
}

void cBase::deleteUnitbyName(string value)
{
	for (vector<cUnit*> ::iterator itr = units->begin(); itr != units->end();)
	{
		if ((*itr)->getName() == value)
		{
			itr = units->erase(itr);
		}
		else
		{
			itr++;
		}
	}
	this->countStats();
}

void cBase::deleteUnitbyUN(string value)
{
	
	for (vector<cUnit*> ::iterator itr = units->begin(); itr != units->end();)
	{
		if ((*itr)->getUN() == value)
		{
			itr = units->erase(itr);
		}
		else
		{
			itr++;
		}
	}
	this->countStats();
}

void cBase::Generate(cObject *world, string value)
{
	int damage = value[6] % 10 + 2;
	int radius = value[5] % 10 + 10;
	int barmor = value[4] % 21 + 40;
	int carmor = value[10] % 21 + 20;
	int carrysize = value[11]%21 + 80;

	for (int i = 0; i < value[3] % 10 + 2; i++)
	{
		this->units->push_back(new cGunner(cUnit(cPosited(cObject("War Unit", "War unit, used to destroy enemy"), this->X() + i, this->Y()), barmor), new cGun(cObject("Gun", "The thing used to strike"), radius, damage)));

	}
	for (int i = 0; i < value[9] % 10 + 4; i++)
	{
		this->units->push_back(new cTanker(cUnit(cPosited(cObject("Harvest unit", "Harvest unit? used to get recourses"), this->X(), this->Y() + i), carmor), new cTank(cObject("Tank", "The thing used to bring resources"), 0, carrysize)));

	}
}

void cBase::moveUp(iAccess * world)
{

}
void cBase::moveDown(iAccess * world)
{

}
void cBase::moveLeft(iAccess * world)
{

}
void cBase::moveRight(iAccess * world)
{

}

void cBase::doAction(iAccess *world, cObject *commited)
{
	//do race spell on commited
}

cObject* cBase::at(int x, int y)
{
	for each(cUnit* current in *this->getAllUnits())
	{
		if (current->X() == x && current->Y() == y)
			return current;
	}
	return &cObject("empty", "");
}
cObject* cBase::at(pair<int, int> value)
{
	return this->at(value.first, value.second);
}

pair<int, int> cBase::position(string value)
{
	for each(cUnit* current in *this->getAllUnits())
	{
		if (current->getUN() == value)
			return pair<int, int>(current->X(), current->Y());
	}
	pair<int, int>(-1, -1);
}

vector<cObject*> cBase::getAround(int x, int y, int r)
{
	vector<cObject*> res;
	for each(cPosited* obj in *this->getAllUnits())
	{
		long long dist = (obj->X() - x)*(obj->X() - x) + (obj->Y() - y)*(obj->Y() - y);
		if (r*r > dist)
			res.push_back(obj);
	}
	return res;
}

