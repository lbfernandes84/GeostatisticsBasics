#pragma once
#include "variograms/Variogram.h"

class Spherical : public Variogram {
public:
	Spherical() : Variogram() {};
	Spherical(double nugget, double sill, double range) : Variogram(nugget, sill, range) {};
private:
	double Model(const double& h, const double& C) const override;
};

