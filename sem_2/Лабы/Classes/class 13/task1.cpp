#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>

#include "Time.h"

using namespace std;

typedef deque<Time> TimeDeque;

TimeDeque make_deque(int n) {
    TimeDeque values;

    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << endl;

        Time value;
        cin >> value;

        values.push_back(value);
    }

    return values;
}

void print_deque(const TimeDeque& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    for_each(values.begin(), values.end(), [](const Time& value) {
        cout << value << " ";
        });

    cout << endl;
}

Time average_deque(const TimeDeque& values) {
    Time sum = accumulate(values.begin(), values.end(), Time());

    return sum / static_cast<int>(values.size());
}

void add_element_to_end_by_key(TimeDeque& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Time key;

    cout << "Введите элемент для поиска:" << endl;
    cin >> key;

    TimeDeque::iterator it = find(values.begin(), values.end(), key);

    if (it == values.end()) {
        cout << "Элемент не найден" << endl;
        return;
    }

    values.push_back(*it);

    cout << "Найденный элемент добавлен в конец контейнера" << endl;
}

void delete_element_by_key(TimeDeque& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Time key;

    cout << "Введите элемент для удаления:" << endl;
    cin >> key;

    TimeDeque::iterator it = find(values.begin(), values.end(), key);

    if (it == values.end()) {
        cout << "Элемент не найден" << endl;
        return;
    }

    values.erase(it);

    cout << "Элемент удален" << endl;
}

void add_average_to_all(TimeDeque& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Time avg = average_deque(values);

    cout << "Среднее арифметическое = " << avg << endl;

    transform(values.begin(), values.end(), values.begin(), [avg](const Time& value) {
        return value + avg;
        });
}

void task1() {
    int n;

    cout << endl << "Задача 1. Последовательный контейнер deque<Time>" << endl;
    cout << "Количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше нуля" << endl;
        return;
    }

    TimeDeque values = make_deque(n);

    cout << endl << "Исходный контейнер:" << endl;
    print_deque(values);

    cout << endl << "Поиск элемента и добавление его в конец:" << endl;
    add_element_to_end_by_key(values);
    print_deque(values);

    cout << endl << "Поиск элемента и удаление его из контейнера:" << endl;
    delete_element_by_key(values);
    print_deque(values);

    cout << endl << "Добавление среднего арифметического к каждому элементу:" << endl;
    add_average_to_all(values);
    print_deque(values);
}