#include "Vanilla1.h"

VanillaOption::VanillaOption(PayOff&ThePayOff_, double Expiry_)
                        : ThePayOff(ThePayOff_), Expiry(Expiry_)
{
}

double VanillaOption::getExpiry() const {return Expiry;}

double VanillaOption::OptionPayOff(double Spot) const {return ThePayOff(Spot);}
