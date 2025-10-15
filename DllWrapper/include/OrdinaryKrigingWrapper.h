#pragma once

#include "DllWrapper_API.h"
#include "Entities/SampleSet.h"
#include "Entities/SampleValues.h"
#include "variograms/Variogram.h"
#include "covariance/CovarianceMatrixBuilder.h"
#include "Ordinarykriging/Ordinarykriging.h"

extern "C"
{
	DLLWRAPPER_API OrdinaryKriging* OrdinaryKrigingEstimate_Create(SampleSet* pSamples);
	DLLWRAPPER_API void OrdinaryKrigingEstimate_Estimate(OrdinaryKriging* pOK, Variogram* pVariogram, SampleValues* pSampleValues, Point* pTarget, EstimationResult* result);
	DLLWRAPPER_API EstimationResult* OKEstimationResult_Create();
}