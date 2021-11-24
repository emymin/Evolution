#include "Creature.h"
#include <math.h> 
#include "Utils.h"

#define PI 3.14159265


Creature::Creature() : Creature::Creature(Genes(),false) {};


Creature::Creature(Genes _genes,bool mutate) {
	genes = _genes;
	if (mutate) genes.Mutate();
	lines = GenerateVertexArray(genes);
	angle = RandomGen::RandomFloat(0, 2 * PI);
	bounds = lines.getBounds();
}

sf::VertexArray Creature::GenerateVertexArray(Genes gen) {
	sf::VertexArray vertarr(sf::Lines, gen.segments.size() * 2 * gen.symmetry);

	sf::Vector2f curPos;
	sf::Vector2f zero(0, 0);
	sf::Vector2f pointCenter = zero;
	
	float curAngle = 0;
	float curRadians = 0;
	float symmetryAngle = 360 / gen.symmetry;

	Segment* curSeg;
	int index = 0;
	int simIndex = 0;
	for (int j = 0; j < gen.symmetry; j++) {
		curAngle = j * symmetryAngle;
		curPos = zero;
		for (int i = 0; i < gen.segments.size(); i++) {
			curSeg = &(gen.segments[i]);
			index = i * 2 + simIndex;
			pointCenter += curPos;
			vertarr[index].position = curPos;
			vertarr[index].color = curSeg->color;
			curAngle += curSeg->angle;
			curRadians = curAngle * (PI / 180);
			if (genes.mirror && j%2==0) { curRadians = PI - curRadians - j*symmetryAngle + (j-1)*symmetryAngle; }
			curPos += curSeg->length*sf::Vector2f(cos(curRadians), sin(curRadians));
			pointCenter += curPos;
			index++;
			vertarr[index].position = curPos;
			vertarr[index].color = curSeg->color;

			effects[curSeg->type]++;

		}
		simIndex += gen.segments.size() * 2;
	}
	pointCenter /= (float)gen.segments.size()*2;
	center = pointCenter;
	/*bounds = lines.getBounds();
	bounds.width *= 1.5;
	bounds.height *= 1.5;*/
	return vertarr;
}


//TODO cull drawing based on bounds
void Creature::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const sf::FloatRect& viewport = target.getView().getViewport();
	states.transform *= getTransform();


	if (renderBounds) {
		sf::RenderStates boundstates = states;
		boundstates.transform.translate(sf::Vector2f(bounds.width / -2, bounds.height / -2));
		boundstates.transform.translate(center);

		sf::RectangleShape boundRect(sf::Vector2f(bounds.width, bounds.height));
		
		if (!boundRect.getGlobalBounds().intersects(viewport)) {
			return;
		}

		boundRect.setFillColor(sf::Color::Transparent);
		boundRect.setOutlineThickness(2);
		boundRect.setOutlineColor(sf::Color::Red);
		target.draw(boundRect, boundstates);
	}
	
	target.draw(lines, states);
	
}

void Creature::Update(float deltaTime,World* world) {
	if (!isAlive) { return; }

	if (effects[Propeller]) {
		angle += RandomGen::RandomFloat(-0.3, 0.3);
		sf::Vector2f movement(cos(angle),sin(angle));
		move(speed*movement*deltaTime*100.f);

	}

	float algaeEnergy = effects[Algae] * deltaTime;
	world->oxygen -= algaeEnergy;
	if (world->oxygen < 0) { world->oxygen = 0; algaeEnergy = 0; }

	energy += algaeEnergy;

	energy -= genes.segments.size()*deltaTime;

	if (energy <= 0) {
		Die();
	}
	if (energy > 5000) {
		Birth();
		energy -= 4500;
	}

}

void Creature::Mutate() {
	genes.Mutate();
	lines = GenerateVertexArray(genes);
}


void Creature::Die()
{
	isAlive = false;
}

void Creature::Birth() {
	canBirth = true;
}

