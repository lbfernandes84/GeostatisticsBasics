#pragma once
#include <vector>
#include <Eigen/Dense>

#include "Entities/Point.h"
#include "variograms/Variogram.h"

class CovarianceMatrixBuilder 
{
	std::vector<Point> m_points;
	Eigen::MatrixXd m_covarianceMatrix;

public:
	CovarianceMatrixBuilder(const std::vector<Point>& points) : m_points(points){};
	const Eigen::MatrixXd GetCovarianceMatrix() const;
	Eigen::MatrixXd& GetCovarianceMatrixRef();
	void Build(const Variogram& variogram);
private:
	void ValidateSimetric() const;

};
