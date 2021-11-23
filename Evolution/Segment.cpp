#include "Segment.h"
#include "Utils.h"


Segment::Segment() {
	angle = RandomGen::RandomFloat(0, 120);
	length = RandomGen::RandomFloat(0, 20);
	SetType(SegmentType(RandomGen::RandomInt(0, Segment::segmentTypes - 1)));
}

sf::Color Segment::GetColor(SegmentType type) {
	switch(type){
	case(Algae): return sf::Color::Green;
	case(Feeder): return sf::Color::Red;
	case(Propeller): return sf::Color::Blue;
	default: return sf::Color::White;
	};
}

Segment::Segment(float _length, float _angle, SegmentType _type) {
	angle = _angle;
	length = _length;
	SetType(_type);
}

void Segment::SetType(SegmentType _type) {
	type = _type;
	color = GetColor(type);
}