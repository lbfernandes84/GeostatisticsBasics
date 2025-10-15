#pragma once
#include "../pch.h"

#include "DllWrapper_API.h"
#include "variograms/Spherical.h"
#include "variograms/Exponential.h"
#include "variograms/Gaussian.h"

extern "C"
{
	//Spherical
	DLLWRAPPER_API Spherical* SphericalVariogram_Create(double nugget, double sill, double range);
	DLLWRAPPER_API void SphericalVariogram_Destroy(Spherical* pVariogram);
	DLLWRAPPER_API double SphericalVariogram_Compute(Spherical* pVariogram, double h) noexcept(false);
	
	//Exponential
	DLLWRAPPER_API Exponential* ExponentialVariogram_Create(double nugget, double sill, double range);
	DLLWRAPPER_API void ExponentialVariogram_Destroy(Exponential* pVariogram);
	DLLWRAPPER_API double ExponentialVariogram_Compute(Exponential* pVariogram, double h) noexcept(false);

	//Gaussian
	DLLWRAPPER_API Gaussian* GaussianVariogram_Create(double nugget, double sill, double range);
	DLLWRAPPER_API void GaussianVariogram_Destroy(Gaussian* pVariogram);
	DLLWRAPPER_API double GaussianVariogram_Compute(Gaussian* pVariogram, double h) noexcept(false);
}