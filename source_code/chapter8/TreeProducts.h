#ifndef TREE_PRODUCST_H
#define TREE_PRODUCST_H

class TreeProduct
{
public:
    TreeProduct(double FinalTime_);
    virtual double FinalPayOff(double Spot) const=0;
    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscoutedFutureValue) const=0;
    virtual ~TreeProduct(){}
    virtual TreeProduct* clone() const=0;
    double GetFinalTime() const;

private:
    double FinalTime;
};

#endif