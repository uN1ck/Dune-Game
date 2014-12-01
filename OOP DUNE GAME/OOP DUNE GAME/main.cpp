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
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow");

	sf::Texture texture;
	texture.loadFromFile("floorBasic.bmp");

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 255));
	sprite.setPosition(5, 5);
	//sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));

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
		

	}


	return 0;
}