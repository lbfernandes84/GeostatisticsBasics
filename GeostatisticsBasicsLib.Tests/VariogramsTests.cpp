#include <stdexcept>

#include "pch.h"
#include "variograms/Gaussian.h"
#include "variograms/Exponential.h"
#include "variograms/Spherical.h"


TEST(VariogramBasis, GetNugget) 
{
    Exponential variogram(1.3, 10.0, 25.0);
    EXPECT_EQ(variogram.GetNugget(), 1.3);
}

TEST(VariogramBasis, GetSill)
{
    Exponential variogram(1.3, 10.0, 25.0);
    EXPECT_EQ(variogram.GetSill(), 10);
}

TEST(VariogramBasis, GetRange)
{
    Exponential variogram(1.3, 10.0, 25.0);
    EXPECT_EQ(variogram.GetRange(), 25.0);
}

TEST(VariogramBasis, InvalidNugget)
{    
    EXPECT_THROW(Variogram(-1.0, 10.0, 25.0), std::invalid_argument);
}

TEST(VariogramBasis, InvalidRange)
{
    EXPECT_THROW(Variogram(1.0, 0.0, 25.0), std::invalid_argument);
}

TEST(VariogramBasis, SillLessThanNugget)
{
    EXPECT_THROW(Variogram(5.0, 4.0, 25.0), std::invalid_argument);
}

TEST(VariogramBasis, hNegative)
{
    auto var = Variogram(5.0, 6.0, 25.0);
    EXPECT_THROW(var(-1.0), std::domain_error);
}

TEST(VariogramBasis, emptyConstructor)
{
    auto var = Variogram();
    var.SetParameters(5.0, 6.0, 25.0);
    EXPECT_NEAR(var.GetNugget(), 5.0, 1e-10);
}

TEST(VariogramBasis, callModelBaseClass)
{
    auto var = Variogram(5.0, 6.0, 25.0);
    EXPECT_THROW(var(1.0), std::logic_error);
}

TEST(VariogramSpherical, h0IsEqualNugget)
{
    Spherical variogram(1.3, 10.0, 25.0);
    EXPECT_EQ(variogram(0.0), 1.3);
}

TEST(VariogramSpherical, hGreaterRangeIsEqualNuggetPlusSill)
{
    Spherical variogram(1.3, 10.0, 25.0);
    EXPECT_DOUBLE_EQ(variogram(25.1), 1.3 + 10);
}

TEST(VariogramSpherical, hHalfRange)
{
    Spherical variogram(1.3, 10.0, 25);    
    EXPECT_DOUBLE_EQ(variogram(12.5), 7.28125);
}

TEST(VariogramSpherical, hWithManyDecimals)
{
    Spherical variogram(1.3, 10.0, 25.0);
    EXPECT_DOUBLE_EQ(variogram(5*1.9999999), 6.241599780759997);
}

TEST(VariogramSpherical, hWithManyDecimalsPolimorfism)
{
    Variogram* variogram =  new Spherical(1.3, 10.0, 25.0);
    EXPECT_DOUBLE_EQ(variogram->operator()(5 * 1.9999999), 6.241599780759997);
}

TEST(VariogramExponential, h0IsEqualNugget)
{
    Exponential variogram(1.3, 10.0, 25.0);
    EXPECT_EQ(variogram(0.0), 1.3);
}

TEST(VariogramExponential, hGreaterRangeIsEqualNuggetPlusSill)
{
    Exponential variogram(1.3, 10.0, 25.0);
    EXPECT_NEAR(variogram(25.0), 9.5, 0.1);
}

TEST(VariogramExponential, hHalfRange)
{
    Exponential variogram(1.3, 10.0, 25);
    EXPECT_DOUBLE_EQ(variogram(12.5), 8.0587676067086598);
}


TEST(VariogramExponential, hWithManyDecimalsPolimorfism)
{
    Variogram* variogram = new Exponential(1.3, 10.0, 25.0);
    EXPECT_DOUBLE_EQ(variogram->operator()(5), 5.2253387659819692);
}

