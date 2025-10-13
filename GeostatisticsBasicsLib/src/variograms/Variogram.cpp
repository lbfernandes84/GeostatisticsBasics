#include "variograms\variogram.h"

double Variogram::operator()(const double& h) const
{
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
