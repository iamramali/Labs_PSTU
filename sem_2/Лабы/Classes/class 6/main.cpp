#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Vector a(5);

    cout << "Введите 5 элементов вектора:" << endl;
    cin >> a;

    cout << endl << "Вектор a:" << endl;
    cout << a << endl;

    cout << "Размер вектора a: " << a() << endl;

    cout << endl << "Доступ к элементу по индексу:" << endl;
    cout << "a[2] = " << a[2] << endl;

    a[2] = 100;

    cout << "После изменения a[2] = 100:" << endl;
    cout << a << endl;

    Vector b(5);

    cout << endl << "Введите 5 элементов вектора b:" << endl;
    cin >> b;

    cout << endl << "Вектор b:" << endl;
    cout << b << endl;

    b = a;

    cout << "После присваивания b = a:" << endl;
    cout << b << endl;

    int number;

    cout << endl << "Введите число для умножения вектора a: ";
    cin >> number;

    Vector c = a * number;

    cout << "Результат умножения вектора a на число:" << endl;
    cout << c << endl;

    cout << endl << "Работа с итератором:" << endl;

    Vector::Iterator it = c.last();

    cout << "Последний элемент: " << *it << endl;

    int n;

    cout << "Введите количество шагов для перехода влево: ";
    cin >> n;

    it = it - n;

    cout << "Элемент после перехода влево: " << *it << endl;

    cout << endl << "Последовательный вывод через итератор:" << endl;

    Vector::Iterator p = c.first();

    for (int i = 0; i < c(); i++) {
        cout << *p << " ";
        p++;
    }

    cout << endl;
}