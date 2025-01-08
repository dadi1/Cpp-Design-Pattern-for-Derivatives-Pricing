#include "SimpleMC.h"
#include <iostream>

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    long NumberOfPaths;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff pytPayOff(Strike, PayOff::put);

/*
    double resultCCall = SimpleMonterCarlo2(callPayOff,
                                            Expiry,
                                            Spot,
                                            Vol,
                                            r,
                                            NumberOfPaths)

    double resultPut = SimpleMonterCarlo2(putPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumerOfPaths)

*/

    return 0;
}
