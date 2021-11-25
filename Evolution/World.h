#pragma once

#include <vector>
#include "Creature.h"

class Creature;

class World : public sf::Drawable

{
public:
	std::vector<Creature> creatures;
	float oxygen;
	bool showBoundingBoxes = false;

	World();
	World(int n);
	void Update(float deltaTime);
	void PopulateRandom(int n);

	void AddCreature(Creature creature);
	void AddCreature(Genes genes, sf::Vector2f position = {0,0});

	void RemoveCreature(int i);

	void ToggleAllBounds();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

