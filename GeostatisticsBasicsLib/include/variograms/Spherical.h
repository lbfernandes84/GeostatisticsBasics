#pragma once
#include "variograms/Variogram.h"

class Spherical : public Variogram {
public:
	Spherical(double nugget, double sill, double range) : Variogram(nugget, sill, range) {};
private:
	virtual double Model(const double& h, const double& C) const override;
};

