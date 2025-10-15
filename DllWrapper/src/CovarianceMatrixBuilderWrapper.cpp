#include "../include/DllWrapper_API.h"
#include "../include/CovarianceMatrixBuilderWrapper.h"

extern "C"
{
	DLLWRAPPER_API CovarianceMatrixBuilder* CovarianceMatrixBuilder_Create(SampleSet samples)
	{
		return new CovarianceMatrixBuilder(samples);
	}

	void CovarianceMatrixBuilder_Build(CovarianceMatrixBuilder* builder, Variogram* variogram)
	{
		if (builder)
		{
			builder->Build(*variogram);
		}
	}
	
	DLLWRAPPER_API Eigen::MatrixXd* CovarianceMatrixBuilder_GetCovarianceMatrix(CovarianceMatrixBuilder* builder)
	{
		if (builder)
		{
			return &builder->GetCovarianceMatrixRef();
		}
		return nullptr;
	}
}