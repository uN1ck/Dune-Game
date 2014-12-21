#include <iostream>
#include "cWorld.h"
#include "iNetStream.h"
#include <vector>
#include "iDrawable.h"
#include "iUpdateble.h"

using namespace std;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow");
	cWorld *world = new cWorld();
	//world->Generate()


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

		world->Update();
		for (int x = 0; x < world->getWidth(); x++)
		{
			for (int y = 0; y < world->getHeight(); y++)
			{
				if ((*world->getWorld())[x][y])
				{
					iDrawable *drawable = dynamic_cast<iDrawable*>((*world->getWorld())[x][y]);
					if (drawable)
						window.draw(drawable->getSprite());
				}
			}
		}

		//
		//(sprite);
		window.display();
	}

	return 0;
}