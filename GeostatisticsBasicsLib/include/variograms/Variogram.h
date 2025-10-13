#pragma once

class Variogram {

protected:
		double m_nugget;
		double m_sill;
		double m_range;
public:	
	Variogram(const double& nugget, const double& sill, const double& range) :m_nugget(nugget), m_sill(sill), m_range(range) {};
	virtual ~Variogram() {}
	virtual double operator()(const double& h) const;
	double GetNugget() const;
	double GetSill() const;
	double GetRange() const;
private:
	virtual double Model(const double& h, const double& C) const = 0;
};
