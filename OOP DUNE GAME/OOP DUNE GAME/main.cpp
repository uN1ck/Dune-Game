#include <iostream>
#include "cWorld.h"
#include "iNetStream.h"
#include <vector>

using namespace std;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void saveBinary(vector<iNetStream *> * value, System::String^ name = "unit.data")
{
	FileStream ^ w_fstream = gcnew FileStream(name, FileMode::Create);
	BinaryWriter ^ o_writer = gcnew BinaryWriter(w_fstream);

	try{
		for (vector<iNetStream *>::iterator r = value->begin(); r != value->end(); r++)
		{
			cout << dynamic_cast<iStringable*>(*r)->toString() << endl;
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

void loadBinary(vector<iNetStream *> * value, System::String^ name = "unit.data")
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

int main()
{
	
	

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