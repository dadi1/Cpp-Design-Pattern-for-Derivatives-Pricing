#ifndef SIMPLEMC8_H
#define SIMPLEMC8_H

#include "../chapter4/Vanilla3.h"
#include "../chapter4/Parameters.h"
#include "Random2.h"
#include "../chapter5/Statistics.h"

void SimpleMinterCalor6(const VanillaOption& TheOption,
                        double Spot,
                        const Parameters& Vol,
                        const Parameters& r,
                        long NumberOfPaths,
                        StatisticsMC& gatherer,
                        RandomBase& generator);

#endif