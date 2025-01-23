#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

#pragma warning( disable : 4786 )

#include "TreeProducts.h"
#include "../chapter6/Array.h"
#include "../chapter4/Parameters.h"

#include <vector>


class SimpleBinomialTree
{
public:
    SimpleBinomialTree(double Spot_,
                       const Parameters& r_,
                       const Parameters& d_,
                       double Volatility_,
                       long Steps,
                       double Time);
    double GetThePrice(const TreeProduct& TheProduct);

protected:
    void BuildTree();

private:
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    long Steps;
    double Time;
    bool TreeBuilt;

    std::vector<std::vector<std::pair<double, double> > >
        TheTree;
    MJArray Discounts;

};

#endif