#include "utils/utils.h"
#include "covariance/CovarianceMatrixBuilder.h"

const Eigen::MatrixXd CovarianceMatrixBuilder::GetCovarianceMatrix() const
{
	return m_covarianceMatrix;
}

Eigen::MatrixXd& CovarianceMatrixBuilder::GetCovarianceMatrixRef()
{
    return m_covarianceMatrix;
}

void CovarianceMatrixBuilder::Build()
{
    const int n = static_cast<int>(m_points.size());
    m_covarianceMatrix.resize(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            double h = Utils::EuclidianDistance(m_points[i], m_points[j]);
            double gamma = m_variogram(h);
            double cov = m_variogram.GetSill() - gamma;
            m_covarianceMatrix(i, j) = cov;
            m_covarianceMatrix(j, i) = cov;
        }
    }
}
