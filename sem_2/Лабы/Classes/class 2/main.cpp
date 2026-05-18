#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float mantissa;
    int order;
    string str;

    cout << "Введите данные числа:" << endl;

    cout << "Мантисса: ";
    cin >> mantissa;

    cout << "Порядок: ";
    cin >> order;

    cout << "Строковое представление: ";
    cin >> str;

    cout << endl << "Создание объекта конструктором без параметров:" << endl;
    Number n1;
    n1.show();

    cout << endl << "Создание объекта конструктором с параметрами:" << endl;
    Number n2(mantissa, order, str);
    n2.show();

    cout << endl << "Создание объекта конструктором копирования:" << endl;
    Number n3 = n2;
    n3.show();

    cout << endl << "Изменение полей объекта через сеттеры:" << endl;
    n3.set_mantissa(mantissa + 10);
    n3.set_order(order + 1);
    n3.set_string(str + "_copy");

    n3.show();
}