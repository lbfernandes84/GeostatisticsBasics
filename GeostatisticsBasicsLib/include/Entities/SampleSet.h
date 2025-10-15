#pragma once
#include <vector>
#include "Point.h"

class SampleSet {

private:
	std::vector<Point> m_samples;

public:
	void AddSample(const Point& sample);
	void SetSamples(const std::vector<Point>& samples);
	std::vector<Point>& GetSamplesByRef();
};

