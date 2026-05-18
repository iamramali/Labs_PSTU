#include <iostream>
#include "Object.h"
#include "Pair.h"
#include "Complex.h"
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Vector v(4);

    cout << "Работа с базовым классом PAIR" << endl;

    Pair p1;
    Pair p2;

    cout << endl << "Введите первую пару:" << endl;
    cin >> p1;

    cout << endl << "Введите вторую пару:" << endl;
    cin >> p2;

    cout << endl << "Первая пара:" << endl;
    cout << p1;

    cout << endl << "Вторая пара:" << endl;
    cout << p2;

    cout << endl << "Сложение пар:" << endl;
    cout << p1 + p2;

    cout << endl << "Демонстрация конструктора копирования для PAIR:" << endl;
    Pair p3(p1);
    cout << p3;

    cout << endl << "Демонстрация оператора присваивания для PAIR:" << endl;
    Pair p4;
    p4 = p2;
    cout << p4;

    cout << endl << "Работа с производным классом COMPLEX" << endl;

    Complex c1;
    Complex c2;

    cout << endl << "Введите первое комплексное число:" << endl;
    cin >> c1;

    cout << endl << "Введите второе комплексное число:" << endl;
    cin >> c2;

    cout << endl << "Первое комплексное число:" << endl;
    cout << c1;

    cout << endl << "Второе комплексное число:" << endl;
    cout << c2;

    cout << endl << "Сложение комплексных чисел:" << endl;
    cout << c1 + c2;

    cout << endl << "Вычитание комплексных чисел:" << endl;
    cout << c1 - c2;

    cout << endl << "Умножение комплексных чисел:" << endl;
    cout << c1 * c2;

    cout << endl << "Демонстрация конструктора копирования для COMPLEX:" << endl;
    Complex c3(c1);
    cout << c3;

    cout << endl << "Демонстрация оператора присваивания для COMPLEX:" << endl;
    Complex c4;
    c4 = c2;
    cout << c4;

    Object* o1 = &p1;
    Object* o2 = &p2;
    Object* o3 = &c1;
    Object* o4 = &c2;

    v.Add(o1);
    v.Add(o2);
    v.Add(o3);
    v.Add(o4);

    cout << endl << "Демонстрация полиморфизма через Vector:" << endl;
    cout << v;
}