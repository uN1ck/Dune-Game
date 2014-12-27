#include "cWorld.h"

cWorld::cWorld() : cObject("Default world", "Default world description")
{
	units = new vector< cObject* >();
	bases = new vector< cObject* >();
	height = 0;
	width = 0;
}
cWorld::cWorld(const cWorld& value) : cObject(value)
{
	units = value.units;
	bases = value.bases;
	height = value.height;
	width = value.height;
}

vector< cObject* > *cWorld::getUnits() const
{
	return units;
}
vector< cObject* > *cWorld::getBases() const
{
	return bases;
}

string cWorld::toString()
{
	string result;
	for each(cObject* current in *this->bases)
		result += current->toString() + "=================================\n";
	for each(cObject* current in *this->units)
		result += current->toString() + "=================================\n";
	return result;
}

map <string, string> *cWorld::readFile()
{
	map <string, string> * file = ((cObject*)this)->readFile();
	//this->setName(file->find("#Armor")->second);
	return file;
}

void cWorld::Update()
{
	for each (cObject *current in *this->bases)
	{
		iUpdateble *upd = dynamic_cast<iUpdateble*> (current);
		if (upd)
			upd->Update(this, this);
	}
}

void cWorld::setID()
{
	
	this->ID = typeid(this).name();
	
}
int cWorld::getHeight()
{
	return height;
}
int cWorld::getWidth()
{
	return width;
}
void cWorld::setHeight(int value)
{
	this->height = value;
}
void cWorld::setWidth(int value)
{
	this->width = value;
}

void cWorld::putUnit(cObject* value)
{
	value->setUN( to_string(this->units->size()+1));
	this->units->push_back(value);
}

void cWorld::Generate(string value, bool debug)
{
	if (value.length() >= 8)
	{
		try{
			this->setHeight(value[0] % 100 + 120);
			this->setWidth(value[0] % 100 + 120);

			for (int i = 0; i < value[2] % 3 + 2; i++)
			{
				string baseName = "Base #" + to_string(i);
				cBase *current = new cBase(cUnit(cPosited(cObject(baseName, "The base of player " + to_string(i)), i * 100 + 20, i * 100 + 20), value[4] % 1000 + 200), new vector<cUnit*>(0));
				bases->push_back(current);

				cBase *currentBase = dynamic_cast<cBase*>(current);
				currentBase->Generate(this, value);

				if (debug)
					cout << "========================================\n" << bases->back()->toString() << "\n\n";

				for (int i = 0; i < currentBase->getAllUnits()->size(); i++)
					this->units->push_back(currentBase->getAllUnits()->at(i));
			}

			for (int i = 0; i < value[1] % 10 + 20; i++);
			//создать спасовые поля
		}
		catch (string value)
		{
			throw value;
		}
	}
}

cWorld::~cWorld()
{
	delete units;
	for (vector< cObject* >::iterator i = bases->begin(); i != bases->end(); i++)
		delete *i;
	delete bases;
}

cObject* cWorld::at(int x, int y)
{
	if (x < this->getWidth() && y < this->getHeight())
	{
		for each(cObject *current in *this->bases)
		{
			iAccess *value = dynamic_cast<iAccess *>(current);
			if (value && x < this->getHeight() && y < this->getWidth() && x >= 0 && y <= 0)
				return value->at(x, y);

		}
		return &cObject("empty", "");
	}
	return &cObject("out", "");
}
cObject* cWorld::at(pair<int, int> value)
{
	return this->at(value.first, value.second);
}
pair<int, int> cWorld::position(string value)
{
	for each(cObject *current in *this->bases)
	{
		iAccess *access = dynamic_cast<iAccess *>(current);
		if (access)
			return access->position(value);
	}
	return (pair<int, int>(-1, -1));
}

static string generateSEED(){
	string res;
	for (int i = 0; i < 16; i++)
		res.push_back(rand() % 1001);
}

vector<cObject*> cWorld::getAround(int x, int y, int r)
{
	vector<cObject*> res;
	for each(cObject* obj in *this->getBases())
	{
		iAccess* current = dynamic_cast<iAccess*>(obj);
		if (current)
		{
			vector<cObject*> temp = current->getAround(x, y, r);
			res.insert(temp.begin(), temp.begin(), temp.end());
		}
	}
	return res;
}
