#include <iostream>
#include <complex>


using namespace std;

int takeAway(int first, int second) {
    return first - second;
}

complex<double> takeAway(complex<double> first, complex<double> second) {
    return first - second;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int num1 = 45, num2 = 17;
    complex<double> z1(8, 5), z2(3, 2);
    complex<double> z3 = takeAway(z1, z2);

    cout << "Разность целых чисел: " << takeAway(num1, num2) << endl;
    cout << "Разность комплексных чисел: " << z3.real();
}
