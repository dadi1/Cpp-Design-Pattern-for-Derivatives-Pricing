#include "Vanilla3.h"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_,
                             double Expiry_)
                        :   ThePayOff(ThePayOff_), Expiry(Expiry_)
{
}

double VanillaOption::getExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const 
{
    return ThePayOff(Spot);
}