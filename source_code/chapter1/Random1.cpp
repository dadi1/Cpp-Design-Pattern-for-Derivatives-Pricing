#include "Random1.h"
#include <cstdlib>
#include <cmath>

// The basic math function should be in namespace

double GetOneGaussianBySummation() {

    double result = 0;

    for (int j = 0; j < 12; j++) 
        result += rand()/static_cast<double>(RAND_MAX);
    
    result -= 6.0;

    return result;
}

double GetOneGaussianByBoxMuller() {
    
    double x;
    double y;

    double sizeSquared;

    do {
        x = 2.0*std::rand()/static_cast<double>(RAND_MAX) - 1;
        y = 2.0*std::rand()/static_cast<double>(RAND_MAX) - 1;
        sizeSquared = x*x + y*y;
    }
    while (sizeSquared >= 1.0);

     return x*std::sqrt(-2 * std::log(sizeSquared)/ sizeSquared);
}