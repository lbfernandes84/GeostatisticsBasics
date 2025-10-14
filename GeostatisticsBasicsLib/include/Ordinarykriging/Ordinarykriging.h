#pragma once
#include <vector>
#include <Eigen/Dense>

#include "variograms/Variogram.h"
#include "covariance/CovarianceMatrixBuilder.h"
#include "Entities/Point.h"


struct EstimationResult
{
	double estimate;
	double variance;
	Eigen::VectorXd weights;
	double lagrange;
};

class OrdinaryKriging {
	std::vector<Point> m_samples;
	Variogram m_variogram;
	
public:
	OrdinaryKriging(const std::vector<Point>& points, const Variogram& variogram) : m_samples(points), m_variogram(variogram) {};
	EstimationResult Estimate(const Eigen::VectorXd& values, const Point& target);

};
	