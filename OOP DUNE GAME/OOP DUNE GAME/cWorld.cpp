#include "cWorld.h"

cWorld::cWorld() : cObject("Default world", "Default world description")
{

	bases = new vector< cObject* >();
	height = 0;
	width = 0;
}
cWorld::cWorld(const cWorld& value) : cObject(value)
{

	bases = value.bases;
	height = value.height;
	width = value.height;
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
	for (vector<cObject *>::iterator current = this->bases->begin(); current != this->bases->end(); current++)
	{
		cUnit *element = dynamic_cast<cUnit*>(*current);
			if (element)
				if (element->getArmor() <= 0)
				{
					current = this->bases->erase(current);
					break;
				}
		iUpdateble *upd = dynamic_cast<iUpdateble*> (*current);
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

void cWorld::Generate(string value, bool debug)
{
	if (value.length() >= 8)
	{
		try{
			this->setHeight(30);
			this->setWidth(30);

			for (int i = 0; i < 2; i++)
			{
				for (int k = 0; k < 2; k++)
				{
					string baseName = "Base #" + to_string(i*2+k);
					cBase *current = new cBase(cUnit(cPosited(cObject(baseName, "The base of player " + to_string(i)), i * 10 + 4, k * 10 + 4), 200), new vector<cUnit*>(0));
					bases->push_back(current);

					cBase *currentBase = dynamic_cast<cBase*>(current);
					currentBase->Generate(this, value);

					if (debug)
						cout << ":::::::::::::::::::::::::::::::::::::::\n" << bases->back()->toString() << "\n\n";
				}
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
	for (vector< cObject* >::iterator i = bases->begin(); i != bases->end(); i++)
		delete *i;
	delete bases;
}

cObject* cWorld::at(int x, int y)
{
	cObject *res = new cObject("empty", "");;
	if (x < this->getHeight() && y < this->getWidth() && x >= 0 && y >= 0)
	{
		for (vector<cObject *>::iterator current = this->bases->begin(); current != this->bases->end(); current++)
		{	
			cPosited *element = dynamic_cast<cPosited*>(*current);
			if (element->X() == x && element->Y() == y)
				return (*current);
		}

		for (vector<cObject *>::iterator current = this->bases->begin(); current != this->bases->end(); current++)
		{
			iAccess *value = dynamic_cast<iAccess *>(*current);
			if (value && res->getName()=="empty")
				res = value->at(x, y);
		}
		return res;
	}
	return new cObject("out", "");
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

vector<cObject*> cWorld::getAround(int x, int y, int r, cObject *base)
{
	vector<cObject*> res;
	for each(cPosited* obj in *this->getBases())
	{
		if (obj->getName() != base->getName())
		{
			if ( ((obj->X() - x)*(obj->X() - x) + (obj->Y() - y)*(obj->Y() - y))<r*r)
				res.push_back(obj);
			iAccess* current = dynamic_cast<iAccess*>(obj);
			if (current)
			{
				vector<cObject*> temp = current->getAround(x, y, r, obj);
				res.insert(res.end(), temp.begin(), temp.end());
			}
		}
	}
	return res;
}
