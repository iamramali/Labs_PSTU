#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int count, ...) {
    va_list nums;
    va_start(nums, count);

    int total = 0;
    for (int i = 0; i < count / 2; i++) {
        int first = va_arg(nums, int);
        int second = va_arg(nums, int);
        total += first * second;
    }

    va_end(nums);
    return total;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Сумма произведений для 8 чисел: " << sum(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;
    cout << "Сумма произведений для 10 чисел: " << sum(10, 2, 4, 1, 5, 3, 6, 7, 2, 8, 1) << endl;
    cout << "Сумма произведений для 12 чисел: " << sum(12, 1, 3, 2, 5, 4, 7, 6, 9, 8, 2, 10, 1) << endl;
}
