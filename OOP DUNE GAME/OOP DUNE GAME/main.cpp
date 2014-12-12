#include <iostream>
#include "cWorld.h"
#include "iNetStream.h"
#include <vector>

using namespace std;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	
	vector<iNetStream *> *res = new vector<iNetStream *>();

	res->push_back(new cUnit(cObject("Name", "Description"), 12));
	res->push_back(new cObject("I'm OBject 1", "I'm an object, man!"));
	res->push_back(new cObject("I'm OBject 2", "I'm an object, man!"));
	res->push_back(new cObject("I'm OBject 3", "Yeah!"));

	FileStream ^ w_fstream = gcnew FileStream("unit.data", FileMode::Create);
	BinaryWriter ^ o_writer = gcnew BinaryWriter(w_fstream);
	try{
		for (vector<iNetStream *>::iterator r = res->begin(); r != res->end(); r++)
		{
			cout << dynamic_cast<iStringable*>(*r)->toString() << endl;
			(*r)->saveToStream(o_writer);
		}
		res->clear();
	}
	catch (...)
	{
		throw gcnew System::Exception("\nIncorrect stream save!");
	}
	__finally
	{
		o_writer->Close();
		w_fstream->Close();
	}

	system("pause");

	FileStream ^ r_fstream = gcnew FileStream("unit.data", FileMode::Open);
	BinaryReader ^ r_writer = gcnew BinaryReader(r_fstream);

	try{
		while(r_writer->PeekChar() != -1)
		{
			string tpe = cObject::ConvertTo( r_writer->ReadString() );
			iNetStream *current;
			if (tpe == "class cUnit *")
			{
				current = new cUnit();
				current->loadFromStream(r_writer);
			}
			if (tpe == "class cObject *")
			{
				current = new cObject();
				current->loadFromStream(r_writer);
			}
			res->push_back(current);
		}
	}
	catch (...)
	{
		throw gcnew System::Exception("\nIncorrect stream read!");
	}
	__finally
	{
		r_writer->Close();
		r_fstream->Close();
	}
	for (vector<iNetStream *>::iterator r = res->begin(); r != res->end(); r++)
		cout << dynamic_cast<iStringable*>(*r)->toString() << endl;
	system("pause");


	/*sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow");
	cWorld *world = new cWorld();
	world->Generate()


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	 	window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
		*/

	


	return 0;
}