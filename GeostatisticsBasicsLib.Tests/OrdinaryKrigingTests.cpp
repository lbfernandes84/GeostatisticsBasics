#include "pch.h"
#include <Eigen/Dense>
#include "Entities/Point.h"
#include "variograms/Spherical.h"
#include "Ordinarykriging/Ordinarykriging.h"

TEST(Ordinarykriging, EstimateSamePoint)
{
    std::vector<Point> samples = {
        {0,0,0},
        {10,0,0}
    };
    auto variogram = Spherical(0.0, 1.0, 10.0);
    auto OKEstimator = OrdinaryKriging(samples, variogram);
    auto vals = Eigen::VectorXd(2);
    vals <<  5.0, 15.0;
    auto result = OKEstimator.Estimate(variogram, vals, { 0, 0, 0 });
    EXPECT_NEAR(result.estimate, 5.0, 1e-6);
}

TEST(Ordinarykriging, IntermediatePoint)
{
    std::vector<Point> samples = {
        {0,0,0},
        {10,0,0}
    };
    auto vals = Eigen::VectorXd(2);
    vals << 10.0, 20.0;
    auto variogram = Spherical(0.0, 1.0, 10.0);
    auto OKEstimator = OrdinaryKriging(samples, variogram);
    auto result = OKEstimator.Estimate(variogram, vals, { 5, 0, 0 });
    EXPECT_NEAR(result.estimate, 15.0, 1.0);
}

TEST(Ordinarykriging, WheightsSum)
{
    std::vector<Point> samples = {
        {0,0,0},
        {10,0,0}
    };
    auto vals = Eigen::VectorXd(2);
    vals << 5.0, 15.0;
    auto variogram = Spherical(0.0, 1.0, 10.0);
    auto OKEstimator = OrdinaryKriging(samples, variogram);
    auto result = OKEstimator.Estimate(variogram, vals, { 5, 0, 0 });
    EXPECT_LT(abs(result.estimate - 10), 2.0);
}
