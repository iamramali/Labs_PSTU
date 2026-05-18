#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Time a;
    Time b;
    Time c;
    Time d(2, 30);
    Time e(d);

    int seconds;

    cout << "Объект, созданный конструктором без параметров:" << endl;
    cout << a;

    cout << endl << "Объект, созданный конструктором с параметрами:" << endl;
    cout << d;

    cout << endl << "Объект, созданный конструктором копирования:" << endl;
    cout << e;

    cout << endl << "Введите первый временной интервал:" << endl;
    cin >> a;

    cout << endl << "Введите второй временной интервал:" << endl;
    cin >> b;

    cout << endl << "Первый интервал:" << endl;
    cout << a;

    cout << "Второй интервал:" << endl;
    cout << b;

    if (a == b) cout << endl << "Интервалы равны" << endl;
    if (a != b) cout << endl << "Интервалы не равны" << endl;

    cout << endl << "Введите количество секунд для добавления к первому интервалу: ";
    cin >> seconds;

    c = a + seconds;

    cout << endl << "Результат добавления секунд:" << endl;
    cout << c;
}