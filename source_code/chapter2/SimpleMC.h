#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "PayOff1.h"

double SimpleMonterCarlo2(const PayOff& thePayOff,
                          double Epiry,
                          double Vol,
                          double r,
                          long NumberOfPaths);
                        
#endif