#include "World.h"
#include "Utils.h"
#include <algorithm>

World::World() {
	
}

World::World(int n) {
	creatures = std::vector<Creature>();
	PopulateRandom(n);
	oxygen = 0.f;
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
	creatures.push_back(creature);
}

void World::AddCreature(Genes genes, sf::Vector2f position)
{
	Creature creature(genes, true);
	creature.setPosition(position);
	AddCreature(creature);
}

void World::RemoveCreature(int i) {
	creatures[i] = creatures.back();
	creatures.pop_back();
}


void World::ToggleAllBounds() {
	showBoundingBoxes = !showBoundingBoxes;
	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].renderBounds = showBoundingBoxes;
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
	oxygen += 1000 * deltaTime;
	if (oxygen < 0) { oxygen = 0; }

	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].Update(deltaTime,this);

		
		//if (!creatures[i].isAlive) { RemoveCreature(i); }
		if (creatures[i].canBirth) { AddCreature(creatures[i].genes, creatures[i].getPosition()); }

	}

	auto end = std::remove_if(creatures.begin(),
		creatures.end(),
		[](Creature const& c) {
			return !c.isAlive;
		});
	creatures.erase(end, creatures.end());


}
