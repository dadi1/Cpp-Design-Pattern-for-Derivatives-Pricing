#include "PayOff2.h"
#include <algorithm>

// PayOffCall implemetation

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator() (double Spot) const {
    return std::max(Spot - Strike, 0.0);
}

// PayOffPut implemetation 

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

double PayOffPut::operator() (double Spot) const {
    return std::max(Strike - Spot, 0.0);
}
