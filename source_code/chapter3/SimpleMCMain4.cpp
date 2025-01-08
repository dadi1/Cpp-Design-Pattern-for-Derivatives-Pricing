#include "../chapter2/SimpleMC.h"
#include <iostream>
#include "PayOff2.h"

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    long NumberOfPaths;

    long optionType;

    PayOff* thePayOffPtr;

    if (optionType == 0)
        thePayOffPtr = new PayOffCall(Strike);
    else
        thePayOffPtr = new PayOffPut(Strike);

    double result = SimpleMonteCarlo2(*thePayOffPtr,
                                      Expiry,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPaths);

    delete thePayOffPtr;

    return 0;
}