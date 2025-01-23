#include "PayOffFoward.h"

double PayOffFoward::operator() (double Spot) const
{
    return Spot - Strike;
}

PayOffFoward::PayOffFoward(double Strike_)
                  : Strike(Strike_)
{   
}

PayOff* PayOffFoward::clone() const
{
    return new PayOffFoward(*this);
}