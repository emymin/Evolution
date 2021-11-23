#include "World.h"
#include "Utils.h"
#include <algorithm>

World::World() {
	
}

World::World(int n) {
	creatures = std::vector<Creature>();
	PopulateRandom(n);
}

void World::PopulateRandom(int n) {
	for (int i = 0; i < n; i++) {
		Creature creature;
		bool done = false;
		sf::Vector2f pos;
		pos = sf::Vector2f(RandomGen::RandomInt(-10000, 10000), RandomGen::RandomInt(-10000, 10000));

		/*sf::FloatRect bounds;
		bool noIntersection;
		while (!done) {
			noIntersection = true;
			pos = sf::Vector2f(RandomFloat(-1, 1), RandomFloat(-1, 1));
			pos = pos*10000.0f;
			for (auto it = creatures.begin(); it != creatures.end(); it++) {
				bounds = (*it).getBounds();
				if ( bounds.contains(pos) ) {
					noIntersection = false;
				}
			}
			if (noIntersection) { done = true; }
		}*/

		creature.setPosition(pos);
		AddCreature(creature);
	}
}

void World::AddCreature(Creature creature){
	//creature.world = this;
	creatures.push_back(creature);
}
void World::RemoveCreature(Creature* creature) {
	//creatures.erase(std::remove(creatures.begin(), creatures.end(), *creature), creatures.end());
}

void World::ToggleAllBounds() {
	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].renderBounds = !creatures[i].renderBounds;
	}
}


void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();
	for (int i = 0; i < creatures.size(); i++) {
		target.draw(creatures[i], states);
	}
}

void World::Update(float deltaTime) {
	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].Update(deltaTime);
	}
}
