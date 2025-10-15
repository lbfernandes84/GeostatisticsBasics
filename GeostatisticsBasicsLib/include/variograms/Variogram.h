#pragma once

class Variogram {

protected:
		double m_nugget;
		double m_sill;
		double m_range;
public:	
	Variogram();
	Variogram(const double& nugget, const double& sill, const double& range);
	void SetParameters(const double& nugget, const double& sill, const double& range);
	virtual ~Variogram() = default;
	double operator()(const double& h) const;
	double GetNugget() const;
	double GetSill() const;
	double GetRange() const;
	virtual double Model(const double& h, const double& C) const;
};
