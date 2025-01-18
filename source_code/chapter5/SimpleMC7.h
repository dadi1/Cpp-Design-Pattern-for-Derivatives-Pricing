#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H

#include "../chapter4/Vanilla3.h"
#include "../chapter4/Parameters.h"
#include "Statistics.h"

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       long NumberOfPaths,
                       StatisticsMC& gatherer);

#endif