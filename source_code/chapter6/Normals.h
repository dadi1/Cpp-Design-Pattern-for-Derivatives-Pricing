#include <cmath>
#include <stdexcept>

double InverseCumulativeNormal(double x) {
        if (x <= 0.0 || x >= 1.0) {
            throw std::out_of_range("Input to InverseCumulativeNormal must be in the range (0, 1)");
        }

        // Constantes da aproximação de Moro
        static const double a[] = {
            2.50662823884,
            -18.61500062529,
            41.39119773534,
            -25.44106049637
        };

        static const double b[] = {
            -8.47351093090,
            23.08336743743,
            -21.06224101826,
            3.13082909833
        };

        static const double c[] = {
            0.3374754822726147,
            0.9761690190917186,
            0.1607979714918209,
            0.0276438810333863,
            0.0038405729373609,
            0.0003951896511919,
            0.0000321767881768,
            0.0000002888167364,
            0.0000003960315187
        };

        double y = x - 0.5;
        if (std::fabs(y) < 0.42) {
            // Região central
            double z = y * y;
            double numerator = ((a[3] * z + a[2]) * z + a[1]) * z + a[0];
            double denominator = (((b[3] * z + b[2]) * z + b[1]) * z + b[0]) * z + 1.0;
            return y * numerator / denominator;
        } else {
            // Caudas
            double r = x;
            if (y > 0.0) {
                r = 1.0 - x;
            }
            r = std::log(-std::log(r));
            double result = c[0];
            for (int i = 1; i < 9; ++i) {
                result += c[i] * std::pow(r, i);
            }
            return (y < 0.0) ? -result : result;
        }
}