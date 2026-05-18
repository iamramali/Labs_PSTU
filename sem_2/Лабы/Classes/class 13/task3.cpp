#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>

#include "Time.h"

using namespace std;

typedef multimap<int, Time> TimeMap;

TimeMap make_map(int n) {
    TimeMap values;

    for (int i = 0; i < n; i++) {
        int key;
        Time value;

        cout << "Ключ элемента " << i + 1 << ": ";
        cin >> key;

        cout << "Значение элемента " << i + 1 << endl;
        cin >> value;

        values.insert(make_pair(key, value));
    }

    return values;
}

void print_map(const TimeMap& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    for_each(values.begin(), values.end(), [](const pair<const int, Time>& item) {
        cout << "Ключ: " << item.first << " Значение: " << item.second << endl;
        });
}

Time average_map(const TimeMap& values) {
    Time sum = accumulate(values.begin(), values.end(), Time(), [](Time current, const pair<const int, Time>& item) {
        return current + item.second;
        });

    return sum / static_cast<int>(values.size());
}

int get_new_key(const TimeMap& values) {
    if (values.empty()) return 0;

    TimeMap::const_reverse_iterator it = values.rbegin();

    return it->first + 1;
}

void add_element_to_end_by_key(TimeMap& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    int key;

    cout << "Введите ключ для поиска: ";
    cin >> key;

    TimeMap::iterator it = values.find(key);

    if (it == values.end()) {
        cout << "Элемент с таким ключом не найден" << endl;
        return;
    }

    int newKey = get_new_key(values);

    values.insert(make_pair(newKey, it->second));

    cout << "Найденный элемент добавлен в конец контейнера с ключом " << newKey << endl;
}

void delete_element_by_key(TimeMap& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    int key;

    cout << "Введите ключ для удаления: ";
    cin >> key;

    TimeMap::iterator it = values.find(key);

    if (it == values.end()) {
        cout << "Элемент с таким ключом не найден" << endl;
        return;
    }

    values.erase(it);

    cout << "Один элемент с заданным ключом удален" << endl;
}

void add_average_to_all(TimeMap& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Time avg = average_map(values);

    cout << "Среднее арифметическое = " << avg << endl;

    for_each(values.begin(), values.end(), [avg](pair<const int, Time>& item) {
        item.second = item.second + avg;
        });
}

void task3() {
    int n;

    cout << endl << "Задача 3. Ассоциативный контейнер multimap<int, Time>" << endl;
    cout << "Количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше нуля" << endl;
        return;
    }

    TimeMap values = make_map(n);

    cout << endl << "Исходный контейнер:" << endl;
    print_map(values);

    cout << endl << "Поиск элемента по ключу и добавление его в конец:" << endl;
    add_element_to_end_by_key(values);
    print_map(values);

    cout << endl << "Поиск элемента по ключу и удаление его из контейнера:" << endl;
    delete_element_by_key(values);
    print_map(values);

    cout << endl << "Добавление среднего арифметического к каждому элементу:" << endl;
    add_average_to_all(values);
    print_map(values);
}