#pragma once

#include "DllWrapper_API.h"
#include "variograms/Variogram.h"
#include "covariance/CovarianceMatrixBuilder.h"
#include "Entities/Point.h"

extern "C"
{
	DLLWRAPPER_API CovarianceMatrixBuilder* CovarianceMatrixBuilder_Create(std::vector<Point> samples);
	DLLWRAPPER_API void CovarianceMatrixBuilder_Build(CovarianceMatrixBuilder* builder, Variogram* variogram);
	DLLWRAPPER_API Eigen::MatrixXd* CovarianceMatrixBuilder_GetCovarianceMatrix(CovarianceMatrixBuilder* builder);
}