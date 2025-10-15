#pragma once
#include <vector>
#include <Eigen/Dense>

#include "Entities/SampleSet.h"
#include "variograms/Variogram.h"

class CovarianceMatrixBuilder 
{
	SampleSet m_samples;
	Eigen::MatrixXd m_covarianceMatrix;

public:
	CovarianceMatrixBuilder(const SampleSet& samples) : m_samples(samples){};
	const Eigen::MatrixXd GetCovarianceMatrix() const;
	Eigen::MatrixXd& GetCovarianceMatrixRef();
	void Build(const Variogram& variogram);
private:
	void ValidateSimetric() const;

};
