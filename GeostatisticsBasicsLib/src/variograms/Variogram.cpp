#include <stdexcept>
#include "variograms\variogram.h"

Variogram::Variogram()
{
	m_nugget = 0.0;
	m_sill = 0.0;
	m_range = 0.0;
}

Variogram::Variogram(const double& nugget, const double& sill, const double& range) :m_nugget(nugget), m_sill(sill), m_range(range)
{
	if (nugget < 0)
	{
		throw std::invalid_argument("nugget must be >= 0");
	}
	if (range <= 0)
	{
		throw std::invalid_argument("range must be > 0");
	}
	if (sill < nugget) 
	{
		throw std::invalid_argument("sill must be >= nugget");
	}
}

void Variogram::SetParameters(const double& nugget, const double& sill, const double& range)
{
	if (nugget < 0)
	{
		throw std::invalid_argument("nugget must be >= 0");
	}
	if (range <= 0)
	{
		throw std::invalid_argument("range must be > 0");
	}
	if (sill < nugget)
	{
		throw std::invalid_argument("sill must be >= nugget");
	}
	m_nugget = nugget;
	m_sill = sill;
	m_range = range;
}

double Variogram::operator()(const double& h) const
{
	if (h < 0) 
	{
		throw std::domain_error("distance must be non-negative");
	}
	double C = m_sill - m_nugget;
	return Model(h, C);
}

double Variogram::GetNugget() const
{
	return m_nugget;
}

double Variogram::GetSill() const
{
	return m_sill;
}

double Variogram::GetRange() const
{	
	return m_range;
}


double Variogram::Model(const double& h, const double& C) const
{
	throw std::logic_error("Cannot call this method directly");
	return 0.0;
}
