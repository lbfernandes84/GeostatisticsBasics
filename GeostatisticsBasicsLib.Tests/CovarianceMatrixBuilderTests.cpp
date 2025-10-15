#include "pch.h"

#include "Entities/Point.h"
#include "variograms/Spherical.h"
#include "covariance/CovarianceMatrixBuilder.h"

static SampleSet generateSimplePoints()
{
    std::vector<Point> samples =  {
        {0.0, 0.0, 0.0},
        {5.0, 0.0, 0.0},
        {10.0, 0.0, 0.0}
    };
    SampleSet sampleSet;
    sampleSet.SetSamples(samples);
    return sampleSet;
}

TEST(CovarianceMatrix, SimetricMatrix)
{
    auto samples = generateSimplePoints();
    auto var = Spherical(0.05, 1.0, 10);
    auto builder = CovarianceMatrixBuilder(samples);
    builder.Build(var);
    auto covMatrix = builder.GetCovarianceMatrixRef();    
    EXPECT_EQ(covMatrix.rows(), 3);
    EXPECT_EQ(covMatrix.cols(), 3);
    EXPECT_TRUE(covMatrix.isApprox(covMatrix.transpose(), 1e-12));
}

TEST(CovarianceMatrix, DiagonalEqualsSill)
{
    auto samples = generateSimplePoints();
    auto var = Spherical(0.05, 1.0, 10);
    auto builder = CovarianceMatrixBuilder(samples);
    builder.Build(var);
    auto covMatrix = builder.GetCovarianceMatrixRef();
    for (int diagonalIndex = 0; diagonalIndex < covMatrix.rows(); ++diagonalIndex)
    {
        EXPECT_TRUE((covMatrix(diagonalIndex, diagonalIndex) - var.GetSill()) < 1e-5);
    }    
}

TEST(CovarianceMatrix, SanityDefinedPositive)
{
    auto samples = generateSimplePoints();
    auto var = Spherical(0.00, 1.0, 10);
    auto builder = CovarianceMatrixBuilder(samples);
    builder.Build(var);
    auto covMatrix = builder.GetCovarianceMatrixRef();
    for (int diagonalIndex = 0; diagonalIndex < covMatrix.rows(); ++diagonalIndex)
    {
        EXPECT_TRUE(covMatrix(0, 1) > covMatrix(0, 2));
    }
}