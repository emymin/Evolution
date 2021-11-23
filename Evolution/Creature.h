#pragma once
#include <SFML/Graphics.hpp>
#include "Genes.h"

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

	Creature();
	Creature(Genes _genes,bool mutate=true);
	sf::VertexArray GenerateVertexArray(Genes gen);
	void Update(float deltaTime);
	void Mutate();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

