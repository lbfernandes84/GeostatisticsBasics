#include <cmath>
#include "variograms\Exponential.h"

double Exponential::Model(const double& h, const double& C) const
{
    return m_nugget + C * (1.0 - std::exp(-3.0 * h / m_range));
}
