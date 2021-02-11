#pragma once
#include <SFML/Graphics.hpp>


class Segment
{
public: 
	sf::Color color;
	float angle;
	float length;
	Segment();
	Segment(float _length, float _angle);
};

