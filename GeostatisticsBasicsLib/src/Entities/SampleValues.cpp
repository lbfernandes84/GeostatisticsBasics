#include "Entities/SampleValues.h"

SampleValues::SampleValues(const int& size)
{
	m_values = Eigen::VectorXd(size);
}

void SampleValues::SetValue(const int& index, const double& value)
{
	m_values(index) = value;
}

void SampleValues::SetValues(const std::vector<double>& values)
{
	for (int i = 0; i < values.size(); ++i)
	{
		m_values(i) = values[i];
	}
}

Eigen::VectorXd& SampleValues::GetValuesByreference()
{
	return m_values;
}

