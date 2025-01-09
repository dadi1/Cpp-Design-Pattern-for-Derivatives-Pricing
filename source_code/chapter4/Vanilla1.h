#ifndef VANILLA_H
#define VANILLA_H 

#include "../chapter3/PayOff2.h"

class VanillaOption
{
public:
    VanillaOption(PayOff& ThePayOff_, double Epiry);
    double getExpiry() const;
    double OptionPayOff(double Spot) const;

private:
    double Expiry;
    PayOff& ThePayOff; 

};

#endif