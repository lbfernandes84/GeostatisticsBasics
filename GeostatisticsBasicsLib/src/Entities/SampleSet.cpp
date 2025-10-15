#include "Entities/SampleSet.h"

void SampleSet::AddSample(const Point& sample)
{
	m_samples.emplace_back(sample);
}

void SampleSet::SetSamples(const std::vector<Point>& samples)
{
	m_samples = samples;
}

std::vector<Point>& SampleSet::GetSamplesByRef()
{
	return m_samples;
}
