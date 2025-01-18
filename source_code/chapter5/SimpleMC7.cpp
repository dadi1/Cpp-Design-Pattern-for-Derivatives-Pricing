#include "SimpleMC7.h"
#include "../chapter1/Random1.h"
#include <cmath>

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       long NumberOfPaths,
                       StatisticsMC& gatherer)
{
    double Expiry = TheOption.getExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = std::sqrt(variance);

    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * std::exp(r.Integral(0, Expiry) + itoCorrection);

    double thisSpot;
    double discounting = std::exp(-r.Integral(0, Expiry));

    for(int i =0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * std::exp(rootVariance * thisGaussian);
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff * discounting);
    }

    return;
}