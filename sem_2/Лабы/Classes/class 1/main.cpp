#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Range r;
    double x;

    cout << "Ввод диапазона:" << endl;
    r.Read();

    cout << endl << "Введите число для проверки: ";
    cin >> x;

    cout << endl << "Информация о диапазоне:" << endl;
    r.Show();

    if (r.check(x)) cout << endl << "Число принадлежит диапазону" << endl;
    else cout << endl << "Число не принадлежит диапазону" << endl;

    cout << endl << "Создание диапазона через функцию make_range:" << endl;

    double first, second;

    cout << "Введите левую границу диапазона: ";
    cin >> first;

    cout << "Введите правую границу диапазона: ";
    cin >> second;

    Range r2 = make_range(first, second);

    cout << endl << "Созданный диапазон:" << endl;
    r2.Show();
}