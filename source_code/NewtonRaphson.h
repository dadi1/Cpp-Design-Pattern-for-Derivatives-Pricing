#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

template<class T,double (T::*Value)(double) const,
                 double (T::*Derivative)(double) const,
                 double NewTonRaphson(double Target,
                                      double Start,
                                      double Tolerance,
                                      double T& TheObject)
{
    double y =(TheObject.*Value)(Start);

    double x = Start;

    while ( fabs(y - Target) > Tolerance )
    {
        double d = (TheObject.*Derivate)(x);

        x += (Target - y)/d;
        y = (TheObject.*Value)(x);
    }

    return x;
}

#endif