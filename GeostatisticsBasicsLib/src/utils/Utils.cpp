#include <cmath>
#include "utils/utils.h"

 double Utils::EPSILON = 0.00001;

 double Utils::EuclidianDistance(const Point& p1, const Point& p2)
 {
	 return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2) + std::pow(p2.z - p1.z, 2));
 }
