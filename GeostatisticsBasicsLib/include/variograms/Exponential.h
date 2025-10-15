#pragma once
#include "Variogram.h"


class Exponential : public Variogram {

public:
	Exponential() : Variogram() {};
	Exponential(double nugget, double sill, double range) : Variogram(nugget, sill, range) {};
private:
	virtual double Model(const double& h, const double& C) const override;
};
