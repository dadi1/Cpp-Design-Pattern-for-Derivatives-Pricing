#ifndef SIMPLEMC_H
#define SIMPLEMC_H

double SimpleMonterCarlo2(const PayOff& thePayOff,
                          double Epiry,
                          double Vol,
                          double r,
                          long NumberOfPaths);
                        
#endif