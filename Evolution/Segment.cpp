#include "Segment.h"

Segment::Segment() {
	angle = 45;
	length = 20;
	color = sf::Color::White;
}

Segment::Segment(float _length, float _angle) {
	angle = _angle;
	length = _length;
	color = sf::Color::Red;
}
