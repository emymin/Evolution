#pragma once
#include <SFML/Graphics.hpp>
#include "Genes.h"

class Creature : public sf::Drawable, public sf::Transformable

{
public:
	Genes genes;
	sf::VertexArray lines;
	sf::FloatRect bounds;

	Creature();
	Creature(Genes _genes);
	sf::VertexArray GenerateVertexArray(Genes gen);
	sf::FloatRect getBounds();
	sf::FloatRect getGlobalBounds();
	bool isPointInside(sf::Vector2f pos);
	void Update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

