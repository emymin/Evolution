#pragma once
#include "Segment.h"
#include <vector>
class Genes
{
public:
	std::vector<Segment> segments;
	int symmetry;
	bool mirror;
	Genes();
	Genes(std::vector<Segment> _segments,int _symmetry=1,bool _mirror=false);
	void RandomGenes();
};

