#include <stdexcept>
#include "../include/variograms/Spherical.h"
#include "../include/variograms/Exponential.h"
#include "../include/variograms/Gaussian.h"
#include "../include/VariogramsWrapper.h"

extern "C"
{
	DLLWRAPPER_API Spherical* SphericalVariogram_Create(double nugget, double sill, double range)
	{
		return new Spherical(nugget, sill, range);
	}
	
	DLLWRAPPER_API void SphericalVariogram_Destroy(Spherical* pVariogram)
	{
		if(pVariogram)
		{
			delete pVariogram;
		}
	}
	DLLWRAPPER_API double SphericalVariogram_Compute(Spherical* pVariogram, double h) noexcept(false)
	{
		if (pVariogram)
		{
			return pVariogram->operator()(h);
		}
		throw std::invalid_argument("Null variogram");
	}
	
	DLLWRAPPER_API Exponential* ExponentialVariogram_Create(double nugget, double sill, double range)
	{
		return new Exponential(nugget, sill, range);
	}
	
	DLLWRAPPER_API void ExponentialVariogram_Destroy(Exponential* pVariogram)
	{
		if (pVariogram)
		{
			delete pVariogram;
		}
	}
	
	DLLWRAPPER_API double ExponentialVariogram_Compute(Exponential* pVariogram, double h) noexcept(false)
	{
		if (pVariogram)
		{
			return pVariogram->operator()(h);
		}
		throw std::invalid_argument("Null variogram");
	}
	
	DLLWRAPPER_API Gaussian* GaussianVariogram_Create(double nugget, double sill, double range)
	{
		return new Gaussian(nugget, sill, range);
	}
	
	DLLWRAPPER_API void GaussianVariogram_Destroy(Gaussian* pVariogram)
	{
		if (pVariogram)
		{
			delete pVariogram;
		}
	}
	
	DLLWRAPPER_API double GaussianVariogram_Compute(Gaussian* pVariogram, double h) noexcept(false)
	{
		if (pVariogram)
		{
			return pVariogram->operator()(h);
		}
		throw std::invalid_argument("Null variogram");
	}
}

