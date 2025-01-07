#include <Random1.h>
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
