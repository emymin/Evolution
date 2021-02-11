#include "Genes.h"
#include "Utils.h"

Genes::Genes() {
	RandomGenes();
}


Genes::Genes(std::vector<Segment> _segments, int _symmetry, bool _mirror) {
	segments = _segments;
	symmetry = _symmetry;
	mirror = _mirror;
}

void Genes::RandomGenes() {
	
	int segments_n = RandomInt(1,20);
	symmetry = RandomInt(1,10);
	mirror = false;

	segments = std::vector<Segment>(segments_n);
	
	for (int i = 0; i < segments_n; i++) {
		float angle = RandomInt(0, 120);
		float length = RandomInt(0,20);
		segments.push_back(Segment(length, angle));
	}

}