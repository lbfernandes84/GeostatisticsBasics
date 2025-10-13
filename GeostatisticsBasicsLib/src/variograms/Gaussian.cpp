#include <cmath>
#include "variograms\Gaussian.h"

double Gaussian::Model(const double& h, const double& C) const
{    
    return m_nugget + C * (1.0 - std::exp(-3.0 * std::pow(h / m_range, 2))); 
}
