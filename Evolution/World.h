#include <vector>
#include "Creature.h"
#pragma once
class World : public sf::Drawable

{
public:
	std::vector<Creature> creatures;

	World();
	World(int n);
	void Update(float deltaTime);
	void PopulateRandom(int n);
	void AddCreature(Creature creature);
	void RemoveCreature(Creature* creature);

	void ToggleAllBounds();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

