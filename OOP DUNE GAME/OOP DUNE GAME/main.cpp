#include <iostream>
/*#include "cController.h"
#include "cGun.h"
#include "cTank.h"
#include "cGunner.h"
#include "cTanker.h"
#include "iClonable.h"
#include "iStringable.h"
#include "iUpdateble.h"

#include "cUnit.h"
#include "cBase.h"*/

using namespace std;

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}