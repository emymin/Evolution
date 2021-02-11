#include "World.h"
#include "Utils.h"

World::World() {
	
}

World::World(int n) {
	creatures = std::vector<Creature>(n);
	PopulateRandom(n);
}

void World::PopulateRandom(int n) {
	for (int i = 0; i < n; i++) {
		Creature creature;
		/*bool done = false;
		sf::Vector2f pos;
		while (!done) {
			bool noIntersection = true;
			pos = sf::Vector2f(RandomFloat(-10000, 10000), RandomFloat(-10000, 10000));
			for (std::vector<Creature>::iterator it = creatures.begin(); it != creatures.end(); it++) {
				if (creature.isPointInside(pos)) {
					noIntersection = false;
				}
			}
			if (noIntersection) { done = true; }
		}*/
		sf::Vector2f pos(RandomFloat(n*-20, n*20), RandomFloat(n*-20, n*20));
		creature.setPosition(pos);
		AddCreature(creature);
	}
}

void World::AddCreature(Creature creature){
	creatures.push_back(creature);
}


void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();
	for (int i = 0; i < creatures.size(); i++) {
		target.draw(creatures[i], states);
	}
}

void World::Update() {
	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].Update();
	}
}
