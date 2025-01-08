/*requires
          PayOff2.cpp
          Random1.cpp
          SimpleMc2.cpp
*/
#include "../chapter2/SimpleMC.h"
#include "PayOff2.h"
#include <iostream>

int main() {

    double Expiry;
    double Strike;
    double Spot;
    double vol;
    double r;
    long NumberOfPaths;

    PayOffCall callPayOff(Strike);
    PayOffPut  putPayOff(Strike);

    /*
    double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    double resultPut = SimpleMonteCarlo2(putPayOff,
                                          Epiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);
    */

   return 0;
}