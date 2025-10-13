#include <cmath>
#include "utils/utils.h"
#include "variograms/Spherical.h"

double Spherical::Model(const double& h, const double& C) const
{
    double result;
    if (abs(h) < Utils::EPSILON)
    {
        result = m_nugget;
    }
    else if (abs(h) > Utils::EPSILON && h < m_range)
    {
        double hr = h / m_range;
        result = m_nugget + C * (1.5 * hr - 0.5 * std::pow(hr, 3));
    }
    else 
    {
        result = m_nugget + m_sill;
    }
    return result;
}
