#include <vector>
#include "Creature.h"
#pragma once
class World : public sf::Drawable

{
public:
	std::vector<Creature> creatures;

	World();
	World(int n);
	void Update();
	void PopulateRandom(int n);
	void AddCreature(Creature creature);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

