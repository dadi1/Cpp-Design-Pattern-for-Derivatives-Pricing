#ifdef PARAMETERS_H
#define PARAMETERS_H

class ParametersInner
{

public:
    ParametersInner() {}

    virtual ParametersInner * clone() const=0;
    virtual double Integral(double time1,
                            double time2) const=0;
    virtual double IntegralSquare(double time1,
                                  double time2) const=0;
    virtual ~ParametersInner() {}

private:
};

class Parameters
{

public:
    Parameters(const ParametersInner& innerObject);
    Parameters(const Parameters& original);
    Parameters& operator=(const Parameters& original);
    virtual ~Parameters();

    inline double Integral(double time1,
                           double time2) const=0;
    inline double IntegralSquare(double time1,
                                 double time2) const=0;

    double Mean(double time1, double time2) const;
    double RootMeanSquare(double time1, double time2) const;

private:
    ParamtersInner* InnterObjectPtr;
};

inline double::Parameters::Intergral(double time1,
                                     double time2)
{
    return InnterObjectPtr->Integral(time1, time2);
}

inline double Parameters::IngrealSquare(double time1,
                                        double time2)
{
    retrun InnerObjectPtr->IntegralSquare(time1, time2);
}

class ParametersConstant : public ParametersInner
{
public: 
    ParametersConstant(double Constant);

    virtual ParametersInner* clone() const;
    virtual double Integral(double time1, dobule time2);
    virtual double IntegralSquare(double time1,
                                  double time2) const;

private:
    double Constant;
    double ConstantSqure;
};

#endif