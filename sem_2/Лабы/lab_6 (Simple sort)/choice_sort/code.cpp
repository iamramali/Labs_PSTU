
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int kol = 5;
    int mas[kol] = { 7, 5, 2, 67, 1 };
    int nomer, buf;

    for (int i = 0; i < kol - 1; i++) {
        nomer = i;
        for (int j = i + 1; j < kol; j++) {
            if (mas[j] < mas[nomer]) nomer = j;
        }
        buf = mas[i];
        mas[i] = mas[nomer];
        mas[nomer] = buf;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < kol; i++) cout << mas[i] << " ";
    cout << endl;
}

