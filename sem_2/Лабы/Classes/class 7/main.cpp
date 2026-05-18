#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Работа с вектором int" << endl;

    Vector<int> a(5, 0);
    Vector<int> b(5, 0);

    cout << "Введите 5 элементов первого вектора int:" << endl;
    cin >> a;

    cout << "Введите 5 элементов второго вектора int:" << endl;
    cin >> b;

    cout << "Первый вектор: " << a << endl;
    cout << "Второй вектор: " << b << endl;

    Vector<int> c = a * b;

    cout << "Результат умножения: " << c << endl;
    cout << "Размер первого вектора: " << int(a) << endl;
    cout << "Элемент с индексом 2: " << a[2] << endl;

    Vector<int> d(5, 0);
    d = a;

    cout << "Результат присваивания d = a: " << d << endl;

    cout << endl << "Работа с вектором float" << endl;

    Vector<float> f1(3, 0);
    Vector<float> f2(3, 0);

    cout << "Введите 3 элемента первого вектора float:" << endl;
    cin >> f1;

    cout << "Введите 3 элемента второго вектора float:" << endl;
    cin >> f2;

    cout << "Первый вектор: " << f1 << endl;
    cout << "Второй вектор: " << f2 << endl;
    cout << "Результат умножения: " << f1 * f2 << endl;

    cout << endl << "Работа с вектором double" << endl;

    Vector<double> db1(3, 0);
    Vector<double> db2(3, 0);

    cout << "Введите 3 элемента первого вектора double:" << endl;
    cin >> db1;

    cout << "Введите 3 элемента второго вектора double:" << endl;
    cin >> db2;

    cout << "Первый вектор: " << db1 << endl;
    cout << "Второй вектор: " << db2 << endl;
    cout << "Результат умножения: " << db1 * db2 << endl;

    cout << endl << "Работа с пользовательским классом Time" << endl;

    Time t;

    Vector<Time> t1(2, t);
    Vector<Time> t2(2, t);

    cout << "Введите 2 элемента первого вектора Time:" << endl;
    cin >> t1;

    cout << "Введите 2 элемента второго вектора Time:" << endl;
    cin >> t2;

    cout << "Первый вектор Time: " << t1 << endl;
    cout << "Второй вектор Time: " << t2 << endl;
    cout << "Результат умножения Time: " << t1 * t2 << endl;
}