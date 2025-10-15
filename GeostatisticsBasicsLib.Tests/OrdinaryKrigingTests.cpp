#include "pch.h"
#include <Eigen/Dense>
#include "Entities/Point.h"
#include "Entities/SampleSet.h"
#include "variograms/Spherical.h"
#include "Ordinarykriging/Ordinarykriging.h"

static SampleSet CreateSimpleSampleSet()
{
    SampleSet sampleSet;
    std::vector<Point> samples = {
    {0,0,0},
    {10,0,0}
    };
    sampleSet.SetSamples(samples);
    return sampleSet;
}

TEST(Ordinarykriging, EstimateSamePoint)
{
    auto values = SampleValues(2);
    values.SetValues({ 5.0, 15.});
    auto variogram = Spherical(0.0, 1.0, 10.0);
    auto OKEstimator = OrdinaryKriging(CreateSimpleSampleSet());    
    auto result = OKEstimator.Estimate(variogram, values, { 0, 0, 0 });
    EXPECT_NEAR(result.estimate, 5.0, 1e-6);
}

TEST(Ordinarykriging, IntermediatePoint)
{    
    auto values = SampleValues(2);
    values.SetValues({ 10.0, 20.0 });
    auto variogram = Spherical(0.0, 1.0, 10.0);
    auto OKEstimator = OrdinaryKriging(CreateSimpleSampleSet());
    auto result = OKEstimator.Estimate(variogram, values, { 5, 0, 0 });
    EXPECT_NEAR(result.estimate, 15.0, 1.0);
}

TEST(Ordinarykriging, WheightsSum)
{
    auto values = SampleValues(2);
    values.SetValues({ 5.0, 15.0 });
    auto variogram = Spherical(0.0, 1.0, 10.0);
    auto OKEstimator = OrdinaryKriging(CreateSimpleSampleSet());
    auto result = OKEstimator.Estimate(variogram, values, { 5, 0, 0 });
    EXPECT_LT(abs(result.estimate - 10), 2.0);
}
