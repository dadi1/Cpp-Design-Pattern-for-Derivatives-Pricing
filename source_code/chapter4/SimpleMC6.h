#ifndef SIMPLEMC6_H
#define SIMPLEMC6_H

#include "Vanilla3.h"
#include "Parameters.h"

double SimpleMonterCalor4(const VanillaOption& TheOption,
                          double Spot,
                          const Parameters& Vol,
                          const Parameters& r,
                          long NumberOfPaths);

#endif