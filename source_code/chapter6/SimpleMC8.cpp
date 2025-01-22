#include "SimpleMC8.h"
#include <cmath>
#include "Array.h"

void SimpleMinterCalor6(const VanillaOption& TheOption,
                        double Spot,
                        const Parameters& Vol,
                        const Parameters& r,
                        long NumberOfPaths,
                        StatisticsMC& gatherer,
                        RandomBase& generator)
{
    generator.ResetDimensionality(1);

    double Expiry = TheOption.getExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = std::sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * std::exp(r.Integral(0, Expiry) + itoCorrection);
    
    double thisSpot;
    double discounting = std::exp(-r.Integral(0, Expiry));;

    MJArray VariateArray(1);

    for (long i = 0; i < NumberOfPaths; i++)
    {
        generator.GetGaussians(VariateArray);
        thisSpot = movedSpot * std::exp(rootVariance * VariateArray[0]);;
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff * discounting);
    }

    return;
}