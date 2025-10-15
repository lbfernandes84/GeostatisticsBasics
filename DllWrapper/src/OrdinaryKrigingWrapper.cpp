#include "../include/OrdinaryKrigingWrapper.h"

extern "C"
{
	OrdinaryKriging* OrdinaryKrigingEstimate_Create(SampleSet* pSamples)
	{
		return new OrdinaryKriging(*pSamples);
	}

	void OrdinaryKrigingEstimate_Estimate(OrdinaryKriging* pOK, Variogram* pVariogram, SampleValues* pSampleValues, Point* pTarget, EstimationResult* result)
	{
		if (pOK && pVariogram && pSampleValues && pTarget)
		{
			 *result = pOK->Estimate(*pVariogram, *pSampleValues, *pTarget);			
		}		
	}
	EstimationResult* OKEstimationResult_Create()
	{
		return new EstimationResult;
	}
	
	double OKEstimationResult_GetEstimate(EstimationResult* estimationResult)
	{
		double result = -1.0;
		if (estimationResult)
		{
			result = estimationResult->estimate;
		}
		return result;
	}

	double OKEstimationResult_GetVariance(EstimationResult* estimationResult)
	{
		double result = -1.0;
		if (estimationResult)
		{
			result = estimationResult->variance;
		}
		return result;
	}

	double OKEstimationResult_GetLagrange(EstimationResult* estimationResult)
	{
		double result = -1.0;
		if (estimationResult)
		{
			result = estimationResult->lagrange;
		}
		return result;
	}


}
