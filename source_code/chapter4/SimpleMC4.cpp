#include "SimpleMC4.h"
#include "../chapter1/Random1.h"
#include <cmath>

double MonteCarlo3(const VanillaOption& TheOption,
                   double Spot,
                   double Vol,
                   double r,
                   long NumberOfPaths)
{
    double Expiry = TheOption.getExpiry();
    
    double variance = Vol*Vol * Expiry;
    double rootVariance = std::sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * std::exp(r * Expiry * itoCorrection);
    double thisSpot;
    double runningSum=0;

    for (int i = 0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * std::exp(rootVariance * thisGaussian);
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= std::exp(-r * Expiry);
    return mean;
}