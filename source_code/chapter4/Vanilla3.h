#ifndef VANILLA3_H
#define VANILLA3_H

#include "PayOffBridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge& ThePayOff_,
                  double Expiry);

    double OptionPayOff(double Spot) const;
    double getExpiry() const;

private:
    double Expiry;
    PayOffBridge ThePayOff;
};
#endif