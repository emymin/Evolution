#include <SFML/Graphics.hpp>
#include "Creature.h"
#include "World.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Evolution!");
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1000, 1000));
	window.setView(view);
	World world(10);

	sf::Clock clock;
	float t;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case(sf::Keyboard::R): { view.setCenter(0, 0); break; }
				case(sf::Keyboard::Enter): { world = World(10); break; }
				}
			}
		}

		sf::Vector2f movement(0, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { movement.x = -5; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { movement.x = 5; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { movement.y = -5; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { movement.y = 5; }
		view.move(movement);

		window.setView(view);


		t = clock.getElapsedTime().asSeconds();
		window.clear();

		world.Update();
		window.draw(world);
		

		window.display();
	}

	return 0;
}
