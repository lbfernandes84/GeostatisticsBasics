#pragma once
#include <vector>
#include <Eigen/Dense>

#include "variograms/Variogram.h"
#include "covariance/CovarianceMatrixBuilder.h"
#include "Entities/Point.h"
#include "Entities/SampleValues.h"


struct EstimationResult
{
	double estimate;
	double variance;
	Eigen::VectorXd weights;
	double lagrange;
};


class OrdinaryKriging {
	SampleSet m_samples;
	Variogram m_variogram;
	
public:
	OrdinaryKriging(const SampleSet& samples) : m_samples(samples){};
	EstimationResult Estimate(const Variogram& variogram, SampleValues& values, const Point& target);

};
	