#include "cObject.h"
#include <typeinfo>

//Файловые методы класса
map< string, string >* cObject::readFile()
{
	fstream in_stream;
	string par_name, par_value;
	map< string,string > *file = new map<string,string>();

	in_stream.open(this->getName() + ".txt", std::fstream::in);
	while (!in_stream.eof())
	{
		in_stream >> par_name >> par_value;
		file->emplace(pair<string, string>(par_name, par_value));
	}
	in_stream.close();
	this->setName(file->find("#Name")->second);
	this->setDescription(file->find("#Description")->second);

	return file;
}

//Get-методы класса
string cObject::getName()const
{
	return this->name;
}
string cObject::getDescription()const
{
	return this->description;
}

//Set-методы класса
void cObject::setName(const string &in_name )
{
	name = in_name;
}
void cObject::setDescription(const string &in_description /*Строка описания обьекта*/)
{
	description = in_description;
}

//Конструкторы
cObject::cObject() 
{
	this->setName("Default Initialization");
	this->setDescription("Default Initialization");
	this->setID();
	
}
cObject::cObject(const cObject &in_object) 
{
	this->setName(in_object.getName());
	this->setDescription(in_object.getDescription());
	this->setID();
}
cObject::cObject(const string in_name, const string in_description) 
{
	this->setName(in_name);
	this->setDescription(in_description);
	this->setID();
}

//Интерфейсные методы
string cObject::toString()
{
	return "#Name " + this->getName() + "\n#Description " + this->getDescription() + "\n#ID |" + this->getID() + "|\n";
}
//Деструктор
cObject::~cObject()
{
}

cObject* cObject::operator=(const cObject &value)
{
	if (this == &value)
		return this;
	this->setName(value.getName());
	this->setDescription(value.getDescription());
	return this;
}

string cObject::getID()const
{
	return this->ID;
}
void cObject::setID()
{
	this->ID = typeid(this).name();
}

void cObject::saveToStream(BinaryWriter ^ value){
	
	try{
		value->Write(this->getID().size());
		System::String ^outer = gcnew System::String(this->getID().c_str());
		value->Write(outer);

		value->Write(this->getName().size());
		outer = gcnew System::String(this->getName().c_str());
		value->Write(outer);

		value->Write(this->getDescription().size());
		outer = gcnew System::String(this->getDescription().c_str());
		value->Write(outer);
	}
	catch (System::Exception^e)
	{
		throw e;
	}

}

string cObject::getString(BinaryReader ^value)
{
	int sz = 0;
	string res;
	sz = value->ReadInt32();
	value->ReadChar();
	for (int i = 0; i < sz; i++)
		res.push_back(value->ReadChar());
	return res;
}

void cObject::loadFromStream(BinaryReader ^ value){
	try{
		this->setName(cObject::getString(value));
		this->setDescription(cObject::getString(value));
		this->setID();
	}
	catch (System::Exception^e)
	{
		throw e;
	}
};

string cObject::getUN()
{
	return this->uniqueName;
}
void cObject::setUN(string value)
{
	this->uniqueName = value;
}
