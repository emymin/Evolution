#include "Creature.h"
#include <math.h> 
#include "Utils.h"

#define PI 3.14159265


Creature::Creature() {
	genes = Genes();
	lines = GenerateVertexArray(genes);
	bounds = lines.getBounds();
}


Creature::Creature(Genes _genes) {
	genes = _genes;
	lines = GenerateVertexArray(genes);
	bounds = lines.getBounds();
}

sf::VertexArray Creature::GenerateVertexArray(Genes gen) {
	sf::VertexArray vertarr(sf::Lines, gen.segments.size() * 2 * gen.symmetry);

	sf::Vector2f curPos;
	sf::Vector2f center(0, 0);
	float curAngle = 0;
	float curRadians = 0;
	float symmetryAngle = 360 / gen.symmetry;

	Segment curSeg;
	int index = 0;
	int simIndex = 0;
	for (int j = 0; j < gen.symmetry; j++) {
		curAngle = j * symmetryAngle;
		curPos = center;
		for (int i = 0; i < gen.segments.size(); i++) {
			curSeg = gen.segments[i];
			index = i * 2 + simIndex;
			vertarr[index].position = curPos;
			vertarr[index].color = curSeg.color;
			curAngle += curSeg.angle;
			curRadians = curAngle * (PI / 180);
			curPos += curSeg.length*sf::Vector2f(cos(curRadians), sin(curRadians));
			index++;
			vertarr[index].position = curPos;
			vertarr[index].color = curSeg.color;

		}
		simIndex += gen.segments.size() * 2;
	}
	return vertarr;
}
sf::FloatRect Creature::getBounds() {
	return bounds;
}
sf::FloatRect Creature::getGlobalBounds() {
	return getTransform().transformRect(getBounds());
}

bool Creature::isPointInside(sf::Vector2f pos) {
	return (getGlobalBounds().contains(pos));
}


void Creature::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(lines, states);
}

void Creature::Update() {
	/*sf::Vector2f movement;
	setPosition(getPosition() + movement);*/
}