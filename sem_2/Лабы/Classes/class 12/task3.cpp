#include <iostream>
#include "Time.h"
#include "Vector.h"

using namespace std;

void task3() {
    int n;

    cout << "Количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше нуля" << endl;
        return;
    }

    Vector<Time> v(n);

    cout << endl << "Исходный контейнер:" << endl;
    v.Print();

    cout << endl << "Добавление максимального элемента в конец контейнера:" << endl;
    v.AddMaxToEnd();
    v.Print();

    cout << endl << "Удаление элемента по ключу:" << endl;

    int key;

    cout << "Введите ключ для удаления: ";
    cin >> key;

    v.DeleteByKey(key);
    v.Print();

    cout << endl << "Добавление среднего арифметического ко всем элементам:" << endl;
    v.AddAverageToAll();
    v.Print();
}