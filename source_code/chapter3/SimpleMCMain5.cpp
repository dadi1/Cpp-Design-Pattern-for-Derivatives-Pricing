#include "../chapter2/SimpleMC.h"
#include "DoubleDigital.h"
#include <iostream>

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    long NumberOfPaths;
    double Low, Up;

    PayOffDoubleDigital thePayOff(Low, Up);
    double result = SimpleMonteCarlo2(thePayOff,
                                       Expiry,
                                       Spot,
                                       Vol,
                                       r,
                                       NumberOfPaths);

    return 0;
}