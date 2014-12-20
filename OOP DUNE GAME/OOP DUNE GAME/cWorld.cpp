#include "cWorld.h"

cWorld::cWorld() : cObject("Default world", "Default world description")
{
	units = new vector< cObject* >();
	bases = new vector< cObject* >();
	height = 0;
	width = 0;
	world = new vector< vector< cObject* > >(0, vector< cObject* >());
	
}
cWorld::cWorld(const cWorld& value) : cObject(value)
{
	
	units = value.units;
	bases = value.bases;
	height = value.height;
	width = value.height;
	world = value.world;
	
}

vector< vector< cObject* > > * cWorld::getWorld()
{
	return world;
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
		result += current->toString();
	for each(cObject* current in *this->units)
		result += current->toString();
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
	this->units->push_back(value);
}

void cWorld::Generate(string value)
{
	/*if (value.length() >= 8)
	{
		this->setHeight(value[0] % 10 * 100);
		this->setWidth(value[1] % 10 * 100);

		for (int i = 0; i < value[2] % 11 + 2; i++)
		{
			string baseName = "base" + to_string(i);
			bases->push_back(new cBase(cUnit(cObject(baseName, "The base of player " + to_string(i)), value[4] % 1000 + 200), 0));
			cBase *currentBase = dynamic_cast<cBase*>(bases->back());
			currentBase->Generate(this, value);

			for (int i = 0; i < currentBase->getAllUnits()->size(); i++)
			{
				this->units->push_back(currentBase->getAllUnits()->at(i));
				
				cUnit* currentUnit = dynamic_cast<cUnit*>(this->units->back());
				sf::Sprite current = currentUnit->getSprite();
				currentUnit

			}

		
		}
	}
	*/
}

cWorld::~cWorld()
{
	delete units;
	for (vector< cObject* >::iterator i = bases->begin(); i != bases->end(); i++)
		delete *i;
	delete bases;
	for (vector< vector< cObject* > >::iterator i = world->begin(); i != world->end(); i++)
	{
		for (vector< cObject* > ::iterator k = i->begin(); k != i->end(); k++)
			delete *k;
	}
	delete world;
}

cObject* cWorld::at(int x, int y)
{
	if (x < this->getHeight() && y < this->getWidth() && x >= 0 && y <= 0)
		return (*this->world)[x][y];
	return NULL;
}
cObject* cWorld::at(pair<int, int> value)
{
	return this->at(value.first, value.second);
}
pair<int, int> cWorld::position(string value)
{
	for (int x = 0; x < this->getWidth(); x++)
		for (int y = 0; y < this->getHeight(); y++)
			if ((*this->world)[x][y]->getUN() == value)
				return pair<int, int>(x, y);
	return (pair<int, int>(-1, -1));

}
bool cWorld::place(cObject* value, pair<int, int> position)
{
	int x = position.first;
	int y = position.second;
	if (x < this->getHeight() && y < this->getWidth() && x >= 0 && y <= 0)
		return ((*this->world)[x][y] = value);
	return false;

}