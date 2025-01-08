#include "Random1.h"
#include <iostream>
#include <cmath>

double SimpleMonteCarlo(double Expiry,
                        double Strike,
                        double Spot,
                        double Vol,
                        double r,
                        long NumberOfPaths) 
{
    double variance = Vol * Vol * Expiry;
    double rootVariance = std::sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * std::exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (int i =0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        double thisSpot = movedSpot * std::exp(rootVariance * thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean += std::exp(-r * Expiry);
    return mean;
}

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;

    return 0;
}