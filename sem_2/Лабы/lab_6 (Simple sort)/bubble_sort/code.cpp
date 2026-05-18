#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int size = 5;
    int numbers[size] = { 74,23,8,24,1 };
    int temp;

    for (int pass = 0; pass < size - 1; pass++) {
        for (int pos = 0; pos < size - pass - 1; pos++) {
            if (numbers[pos] > numbers[pos + 1]) {
                temp = numbers[pos];
                numbers[pos] = numbers[pos + 1];
                numbers[pos + 1] = temp;
            }
        }
    }
    cout << "Отсортированный массив:" << endl;
    for (int pos = 0; pos < size; pos++) cout << numbers[pos] << " ";
    cout << endl;
}
