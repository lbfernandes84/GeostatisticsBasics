#pragma once
#include <vector>
#include <Eigen/Dense>

#include "Entities/Point.h"
#include "variograms/Variogram.h"

class CovarianceMatrixBuilder {

	Variogram m_variogram;
	std::vector<Point> m_points;
	Eigen::MatrixXd m_covarianceMatrix;

public:
	CovarianceMatrixBuilder(const std::vector<Point>& points, Variogram variogram) : m_points(points), m_variogram(variogram) {};
	const Eigen::MatrixXd GetCovarianceMatrix() const;
	Eigen::MatrixXd& GetCovarianceMatrixRef();
	void Build();	
};
