#ifndef BLACK_SCHOLES_FORMULAS_H
#define BLACK_SCHOLES_FORMULAR_H

double BlackScholesCall(double Spot, double K, double r, double d, double Vol, double T);

double BlackScholesPut(double Spot, double K, double r, double d, double Vol, double T);

double BlackScholesCallVega(double S, double K, double r, double d, double Vol, double T);

#endif