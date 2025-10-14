#include "Eigen/Dense"

#include "covariance/CovarianceMatrixBuilder.h"
#include "Ordinarykriging/Ordinarykriging.h"
#include "utils/utils.h"

EstimationResult OrdinaryKriging::Estimate(const Variogram& variogram, const Eigen::VectorXd& values, const Point& target)
{
	int samplesCount = m_samples.size();
	CovarianceMatrixBuilder covarianceMatrixBuilder(m_samples);
	covarianceMatrixBuilder.Build(variogram);
	Eigen::MatrixXd& covMatrix = covarianceMatrixBuilder.GetCovarianceMatrixRef();
	Eigen::VectorXd C0(samplesCount);
	for (int i = 0; i < samplesCount; ++i)
	{
		double h = Utils::EuclidianDistance(m_samples[i], target);
		double gamma = variogram(h);
		C0(i) = variogram.GetSill() - gamma;
	}

	//Build aumengted matrix A and b
	Eigen::MatrixXd A(samplesCount + 1, samplesCount + 1);
	A.setZero();
	A.block(0, 0, samplesCount, samplesCount) = covMatrix;
	A.block(0, samplesCount, samplesCount, 1) = Eigen::VectorXd::Ones(samplesCount);
	A.block(samplesCount, 0, 1, samplesCount) = Eigen::RowVectorXd::Ones(samplesCount);
	A(samplesCount, samplesCount) = 0.0;

	Eigen::VectorXd b(samplesCount + 1);
	b.setZero();
	b.head(samplesCount) = C0;
	b(samplesCount) = 1.0;

	// 4) Solve the system using LDLT
	Eigen::LDLT<Eigen::MatrixXd> solver;
	solver.compute(A);
	if (solver.info() != Eigen::Success) {
		throw std::runtime_error("LDLT decomposition failed");
	}
	Eigen::VectorXd x = solver.solve(b);
	if (solver.info() != Eigen::Success) {
		throw std::runtime_error("Solving linear system failed");
	}

	Eigen::VectorXd w = x.head(samplesCount);
	double mu = x(samplesCount);

	// 5) Compute estimate and kriging variance
	double estimate = w.dot(values);
	// kriging variance: sigma_k^2 = sill - w^T c0 - mu
	double sill = m_variogram.GetSill();
	double variance = sill - w.dot(C0) - mu;

	EstimationResult res;
	res.estimate = estimate;
	res.variance = variance;
	res.weights = w;
	res.lagrange = mu;
	return res;		
}
