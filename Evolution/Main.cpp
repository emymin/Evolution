#include <SFML/Graphics.hpp>
#include "World.h"
#include <time.h>
#include "Utils.h"
#include <iostream>

World generateWorld(int n) {
	std::cout << "Generating World" << std::endl;
	sf::Clock worldGenTime;
	World world(n);
	std::cout<<"Generated world in " << worldGenTime.restart().asMilliseconds() << " ms"<<std::endl;
	return world;
}

int main()
{
	RandomGen gen();
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Evolution!");
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1000, 1000));
	sf::Vector2f defaultSize = view.getSize();
	window.setView(view);

	int creature_n=25000;
	//World world = generateWorld(creature_n);
	World world;
	world.AddCreature(Creature());

	sf::Clock clock;
	sf::Clock startClock;
	float deltaTime;
	float FPS;
	float t;
	float movement_multiplier;
	while (window.isOpen())
	{
		movement_multiplier = 1;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed && window.hasFocus()) {
				switch (event.key.code) {
				case(sf::Keyboard::R): { view.setCenter(0, 0); break; }
				case(sf::Keyboard::B): {world.ToggleAllBounds(); break; }
				case(sf::Keyboard::M): {world.creatures[0].Mutate(); break; }
				case(sf::Keyboard::Enter): { world = generateWorld(creature_n); break; }
				}
			}
			if (event.type == sf::Event::Resized) {
				float ratio = event.size.height / event.size.width;
				view.setSize(1000 * ratio, 1000);
				defaultSize = view.getSize();
			}
		}

		deltaTime = clock.restart().asSeconds();
		FPS = 1 / deltaTime;
		t = startClock.getElapsedTime().asSeconds();

		std::string title("Evolution FPS: ");
		title = title + std::to_string((int)FPS) + " " + std::to_string((int)world.oxygen);
		window.setTitle(title.c_str());

		if (window.hasFocus()) {
			sf::Vector2f movement(0, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){ movement_multiplier = 2; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { movement.x = -1; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { movement.x = 1; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { movement.y = -1; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { movement.y = 1; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { view.zoom((1 + (deltaTime*movement_multiplier))); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) { view.zoom(1 / (1 + (deltaTime*movement_multiplier))); }
			view.move(movement*movement_multiplier*(deltaTime * 500));
		}

		window.setView(view);


		window.clear();

		world.Update(deltaTime);
		window.draw(world);
		

		window.display();
	}

	return 0;
}
