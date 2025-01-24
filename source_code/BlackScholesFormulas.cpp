#include "BlackScholesFormulas.h"
#include<cmath>

double calcD1(double S, double K, double r, double sigma, double T) {
    if (S <= 0.0 || K <= 0.0 || sigma <= 0.0 || T <= 0.0) {
        throw("Invalid input values for Black-Scholes formula.");
    }
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

static double normalCDF(double x) {
    return 0.5 * std::erfc(-x * std::sqrt(0.5));
}

// Implementação de callPrice
double BlackScholesCall(double S, double K, double r, double sigma, double T) {
    double d1 = calcD1(S, K, r, sigma, T);
    double d2 = d1 - sigma * std::sqrt(T);
    return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
}

// Implementação de putPrice
double BlackScholesPut(double S, double K, double r, double sigma, double T) {
    double d1 = calcD1(S, K, r, sigma, T);
    double d2 = d1 - sigma * std::sqrt(T);
    return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
}

double BlackScholesCallVega(double S, double K, double r, double sigma, double T) {
    double d1 = calcD1(S, K, r, sigma, T);
    return S * std::sqrt(T) * normalCDF(d1);
}