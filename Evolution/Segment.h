#pragma once
#include <SFML/Graphics.hpp>

enum SegmentType {
	Algae = 0,
	Feeder = 1,
	Propeller = 2,
};

class Segment
{
public: 
	static const int segmentTypes = 3;
	SegmentType type;
	sf::Color color;
	float angle;
	float length;
	Segment();
	Segment(float _length, float _angle, SegmentType _type=Algae);
	sf::Color GetColor(SegmentType type);
	void SetType(SegmentType _type);
};
