#include <iostream>
#include <clocale>
#include "error.h"
#include "vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        Vector a(5);

        cout << "Введите 5 элементов вектора:" << endl;
        cin >> a;

        cout << endl << "Вектор a:" << endl;
        cout << a << endl;

        cout << "Размер вектора a: " << a() << endl;

        cout << endl << "Элемент с индексом 2: " << a[2] << endl;

        a[2] = 100;

        cout << "После изменения a[2] = 100:" << endl;
        cout << a << endl;

        cout << endl << "Постфиксная операция a-- удаляет элемент в конце:" << endl;
        a--;
        cout << a << endl;
        cout << "Размер вектора a: " << a() << endl;

        cout << endl << "Префиксная операция --a удаляет элемент в начале:" << endl;
        --a;
        cout << a << endl;
        cout << "Размер вектора a: " << a() << endl;

        cout << endl << "Демонстрация конструктора копирования:" << endl;
        Vector b(a);
        cout << b << endl;

        cout << endl << "Демонстрация операции присваивания:" << endl;
        Vector c;
        c = a;
        cout << c << endl;
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }

    cout << endl << "Проверка исключительных ситуаций:" << endl;

    try {
        Vector tooBig(MAX_SIZE + 1);
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }

    try {
        Vector negative(-3);
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }

    try {
        Vector v(3, 1);
        cout << v[-1] << endl;
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }

    try {
        Vector v(3, 1);
        cout << v[5] << endl;
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }

    try {
        Vector v;
        v--;
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }

    try {
        Vector v;
        --v;
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }
}