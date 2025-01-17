#ifndef SIMPLEMC4_H
#define SIMPLEMC4_H

#include "Vanilla2.h"

double SimpleMonteCarlo(const VanillaOption& TheOption,
                        double Spot,
                        double Vol,
                        double r,
                        long NumberOfPaths);

#endif

