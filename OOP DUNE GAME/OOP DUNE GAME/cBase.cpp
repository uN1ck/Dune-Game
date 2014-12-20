#include "cBase.h"

using namespace std;

cBase::cBase() : cUnit(cObject("Default base name", "Default Base description"), 1000)
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
	string res = cUnit::toString();
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

void cBase::saveBinary(vector<iNetStream *> * value, System::String^ name = "unit.data")
{
	FileStream ^ w_fstream = gcnew FileStream(name, FileMode::Create);
	BinaryWriter ^ o_writer = gcnew BinaryWriter(w_fstream);

	try{
		for (vector<iNetStream *>::iterator r = value->begin(); r != value->end(); r++)
		{
			(*r)->saveToStream(o_writer);
		}
		value->clear();
	}
	__finally
	{
		o_writer->Close();
		w_fstream->Close();
	}
}

void cBase::loadBinary(vector<iNetStream *> * value, System::String^ name = "unit.data")
{
	FileStream ^ r_fstream = gcnew FileStream(name, FileMode::Open);
	BinaryReader ^ r_writer = gcnew BinaryReader(r_fstream);

	try{
		while (r_writer->PeekChar() != -1)
		{
			string tpe = cObject::getString(r_writer);
			iNetStream *current;

			if (tpe == "class cObject *")
			{
				current = new cObject();
				try{

					current->loadFromStream(r_writer);
					value->push_back(current);
				}
				catch (System::Exception ^ value){
					delete current;
					throw value;
				}
			}
		}
	}
	catch (System::Exception ^ value)
	{
		throw value;
	}
	__finally
	{
		r_writer->Close();
		r_fstream->Close();
	}
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
	for (int i = 0; i < value[3] % 10 + 2; i++)
		this->units->push_back(new cGunner(cUnit(cObject("War Unit", "War unit, used to destroy enemy"), value[5] & 100 + 20), new cGun(cObject("Gun", "The thing used to strike"), value[8] % 10 + 2, value[9] % 50 + 30)));
	for (int i = 0; i < value[4] % 10 + 4; i++)
		this->units->push_back(new cTanker(cUnit(cObject("Harvest unit", "Harvest unit? used to get recourses"), value[5] & 100 + 5), new cTank(cObject("Tank", "The thing used to bring resources"), 0 , value[10]%100+20 )));
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