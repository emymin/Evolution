#pragma once

#include <SFML/Graphics.hpp>
#include "Genes.h"
#include "World.h"

class World;

class Creature : public sf::Drawable, public sf::Transformable

{
public:

	Genes genes;
	sf::VertexArray lines;
	sf::Vector2f center;
	sf::FloatRect bounds;
	bool renderBounds = false;
	int effects[Segment::segmentTypes];

	float energy=100;
	float speed = 1;
	float angle = 0;

	bool isAlive = true;
	bool canBirth = false;

	Creature();
	Creature(Genes _genes,bool mutate=true);
	sf::VertexArray GenerateVertexArray(Genes gen);
	void Update(float deltaTime,World* world);
	void Mutate();
	void Die();
	void Birth();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

