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
}
