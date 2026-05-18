#include <iostream>
#include <map>
#include "Time.h"

using namespace std;

typedef map<int, Time> TMapTime;

TMapTime make_map_time(int n) {
    TMapTime m;
    Time value;

    for (int i = 0; i < n; i++) {
        cout << "Элемент [" << i << "]" << endl;
        cin >> value;
        m[i] = value;
    }

    return m;
}

void print_map_time(const TMapTime& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    for (TMapTime::const_iterator it = m.begin(); it != m.end(); ++it)
        cout << "Ключ: " << it->first << " Значение: " << it->second << endl;
}

Time max_value_time(const TMapTime& m) {
    TMapTime::const_iterator it = m.begin();
    Time mx = it->second;

    for (; it != m.end(); ++it)
        if (it->second > mx) mx = it->second;

    return mx;
}

Time average_time(const TMapTime& m) {
    Time sum;

    for (TMapTime::const_iterator it = m.begin(); it != m.end(); ++it)
        sum = sum + it->second;

    return sum / static_cast<int>(m.size());
}

int new_key_time(const TMapTime& m) {
    if (m.empty()) return 0;

    TMapTime::const_reverse_iterator it = m.rbegin();

    return it->first + 1;
}

void add_max_to_end_time(TMapTime& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Time mx = max_value_time(m);
    int key = new_key_time(m);

    m[key] = mx;

    cout << "Максимальный элемент добавлен в конец контейнера" << endl;
}

void delete_by_key_time(TMapTime& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    int key;

    cout << "Введите ключ для удаления: ";
    cin >> key;

    TMapTime::iterator it = m.find(key);

    if (it == m.end()) {
        cout << "Элемент с таким ключом не найден" << endl;
        return;
    }

    m.erase(it);

    cout << "Элемент удален" << endl;
}

void add_average_to_all_time(TMapTime& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Time sr = average_time(m);

    cout << "Среднее арифметическое = " << sr << endl;

    for (TMapTime::iterator it = m.begin(); it != m.end(); ++it)
        it->second = it->second + sr;
}

void task2() {
    int n;

    cout << "Количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше нуля" << endl;
        return;
    }

    TMapTime m = make_map_time(n);

    cout << endl << "Исходный контейнер:" << endl;
    print_map_time(m);

    cout << endl << "Добавление максимального элемента в конец контейнера:" << endl;
    add_max_to_end_time(m);
    print_map_time(m);

    cout << endl << "Удаление элемента по ключу:" << endl;
    delete_by_key_time(m);
    print_map_time(m);

    cout << endl << "Добавление среднего арифметического ко всем элементам:" << endl;
    add_average_to_all_time(m);
    print_map_time(m);
}