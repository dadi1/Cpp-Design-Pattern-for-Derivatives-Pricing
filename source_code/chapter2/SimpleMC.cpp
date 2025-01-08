#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         long NumberOfPaths) 
{
    double variance = Vol*Vol * Expiry;
    double rootVariance = std::sqrt(variance);
    double itoCorrection = -0.5 * variance;
    
    double movedSpot = Spot * std::exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (int i = 0; i < NumberOfPaths; i ++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * std::exp(rootVariance * thisGaussian);
        double thisPayOff = thePayOff(thisSpot);
        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= std::exp(-r * Expiry);
    return mean;
}