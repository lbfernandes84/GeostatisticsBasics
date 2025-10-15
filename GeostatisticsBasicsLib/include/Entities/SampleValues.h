#pragma once
#include "Eigen/Dense"

class SampleValues {

private:
	Eigen::VectorXd m_values;

public:
	SampleValues(const int& size);
	void SetValue(const int& index, const double& value);
	void SetValues(const std::vector<double>& values);
	Eigen::VectorXd& GetValuesByreference();
};