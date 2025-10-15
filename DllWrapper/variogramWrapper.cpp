//#include "pch.h"
#include "DllWrapper_API.h"
#include "variograms/Spherical.h"
#include "variograms/Exponential.h"
#include "variograms/Gaussian.h"

#include "variograms/Variogram.h"
class DLLWRAPPER_API  VariogramSpherical {

private:
	Spherical m_variogramSpherical;
public:
	VariogramSpherical(double nugget, double sill, double range)
};