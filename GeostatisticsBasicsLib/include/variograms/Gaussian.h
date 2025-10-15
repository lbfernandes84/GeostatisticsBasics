#pragma once
#pragma once
#include "Variogram.h"

class Gaussian : public Variogram {
public:
	Gaussian() : Variogram() {};
	Gaussian(double nugget, double sill, double range) : Variogram(nugget, sill, range) {};
private:
	virtual double Model(const double& h, const double& C) const override;
};

