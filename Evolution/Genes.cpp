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
	
	int segments_n = RandomGen::RandomGeometricInt(0.3)+1;
	symmetry = (int)(RandomGen::RandomGeometricInt(0.4))+1;
	mirror = RandomGen::RandomInt(0,1)&1;
	
	for (int i = 0; i < segments_n; i++) {
		Segment segment;
		if (i == 0) { segment.angle = 0; }
		segments.push_back(segment);
	}

}

void Genes::Mutate() {
	int segmAdd = RandomGen::RandomBinomialInt(segments.size(), 0.1) - segments.size()/3;
	if (segmAdd < 0) {
		if(abs(segmAdd) < segments.size()) {
			int index;
			for (int i = 0; i < abs(segmAdd); i++) {
				index = RandomGen::RandomInt(0, segments.size()-1);
				segments.erase(segments.begin() + index);
			}
		}
	}
	else {
		int index;
		for (int i = 0; i < segmAdd; i++) {
			Segment segment;
			index = RandomGen::RandomInt(0, segments.size()-1);
			segments.insert(segments.begin() + index, segment);
		}
	}
	Segment* seg;
	for (int i = 0; i < segments.size(); i++) {
		seg = &segments[i];
		seg->length += (RandomGen::RandomBinomialInt(100,0.9)-50) / 10;
		if (seg->length < 0) seg->length = 0;
		segments[i].angle += (RandomGen::RandomBinomialInt(100, 0.5) - 50) / 10;
		if (seg->angle < 0) seg->angle = 0;
		if (RandomGen::RandomGeometricInt(0.6) > 4) {
			seg->SetType(SegmentType(RandomGen::RandomInt(0, Segment::segmentTypes - 1)));
		}
	}
	symmetry += (RandomGen::RandomBinomialInt(10, 0.1) - 5);
	if (symmetry < 1)symmetry = 1;
	mirror = mirror && (RandomGen::RandomGeometricInt(0.8) < 4);

}