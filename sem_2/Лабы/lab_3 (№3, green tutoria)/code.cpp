#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    double a = 0.1, b = 0.8, eps = 0.0001;
    int k = 10, n = 10;
    double h = (b - a) / k;

    cout << fixed << setprecision(6);
    cout << "y = x * arctg(x) - ln(sqrt(1 + x^2))" << endl << endl;
    cout << "x\t\tS(n)\t\tS(eps)\t\tТочное значение" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int j = 0; j <= k; j++) {
        double x = a + h * j;
        double t = x * x / 2;
        double sn = t;

        for (int i = 1; i < n; i++) {
            t *= -x * x * (2 * i) * (2 * i - 1) / ((2 * i + 2) * (2 * i + 1));
            sn += t;
        }

        t = x * x / 2;
        double se = 0;
        int i = 1;

        while (fabs(t) >= eps) {
            se += t;
            t *= -x * x * (2 * i) * (2 * i - 1) / ((2 * i + 2) * (2 * i + 1));
            i++;
        }

        double y = x * atan(x) - log(sqrt(1 + x * x));
        cout << x << "\t\t" << sn << "\t" << se << "\t" << y << endl;
    }
}
