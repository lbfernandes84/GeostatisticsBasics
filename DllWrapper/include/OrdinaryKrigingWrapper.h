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
	//EstimationResult attributes
	DLLWRAPPER_API EstimationResult* OKEstimationResult_Create();
	DLLWRAPPER_API double OKEstimationResult_GetEstimate(EstimationResult* estimationResult);
	DLLWRAPPER_API double OKEstimationResult_GetVariance(EstimationResult* estimationResult);
	DLLWRAPPER_API double OKEstimationResult_GetLagrange(EstimationResult* estimationResult);
}