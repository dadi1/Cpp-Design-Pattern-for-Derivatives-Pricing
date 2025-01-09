#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H
#include "Vanilla1.h"

double simpleMonterCarlo3(const VanillaOption& TheOption,
                          double Spot,
                          double vol,
                          double r,
                          long NumerOfPaths);

#endif