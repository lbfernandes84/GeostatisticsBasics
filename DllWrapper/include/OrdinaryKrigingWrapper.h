#pragma once

#include "DllWrapper_API.h"
#include "Entities/Point.h"
#include "variograms/Variogram.h"
#include "covariance/CovarianceMatrixBuilder.h"
#include "Ordinarykriging/Ordinarykriging.h"

extern "C"
{
	DLLWRAPPER_API CovarianceMatrixBuilder* CovarianceMatrixBuilder_Create(std::vector<Point> samples);
}