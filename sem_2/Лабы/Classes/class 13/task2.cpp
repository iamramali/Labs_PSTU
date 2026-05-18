#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>

#include "Time.h"

using namespace std;

typedef queue<Time> TimeQueue;

deque<Time> queue_to_deque(TimeQueue values) {
    deque<Time> result;

    while (!values.empty()) {
        result.push_back(values.front());
        values.pop();
    }

    return result;
}

TimeQueue deque_to_queue(const deque<Time>& values) {
    TimeQueue result;

    for_each(values.begin(), values.end(), [&result](const Time& value) {
        result.push(value);
        });

    return result;
}

TimeQueue make_queue(int n) {
    TimeQueue values;

    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << endl;

        Time value;
        cin >> value;

        values.push(value);
    }

    return values;
}

void print_queue(TimeQueue values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    while (!values.empty()) {
        cout << values.front() << " ";
        values.pop();
    }

    cout << endl;
}

Time average_queue(const TimeQueue& values) {
    deque<Time> data = queue_to_deque(values);
    Time sum = accumulate(data.begin(), data.end(), Time());

    return sum / static_cast<int>(data.size());
}

void add_element_to_end_by_key(TimeQueue& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    deque<Time> data = queue_to_deque(values);
    Time key;

    cout << "Введите элемент для поиска:" << endl;
    cin >> key;

    deque<Time>::iterator it = find(data.begin(), data.end(), key);

    if (it == data.end()) {
        cout << "Элемент не найден" << endl;
        return;
    }

    data.push_back(*it);
    values = deque_to_queue(data);

    cout << "Найденный элемент добавлен в конец контейнера" << endl;
}

void delete_element_by_key(TimeQueue& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    deque<Time> data = queue_to_deque(values);
    Time key;

    cout << "Введите элемент для удаления:" << endl;
    cin >> key;

    deque<Time>::iterator it = find(data.begin(), data.end(), key);

    if (it == data.end()) {
        cout << "Элемент не найден" << endl;
        return;
    }

    data.erase(it);
    values = deque_to_queue(data);

    cout << "Элемент удален" << endl;
}

void add_average_to_all(TimeQueue& values) {
    if (values.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    deque<Time> data = queue_to_deque(values);
    Time avg = average_queue(values);

    cout << "Среднее арифметическое = " << avg << endl;

    transform(data.begin(), data.end(), data.begin(), [avg](const Time& value) {
        return value + avg;
        });

    values = deque_to_queue(data);
}

void task2() {
    int n;

    cout << endl << "Задача 2. Адаптер контейнера queue<Time>" << endl;
    cout << "Количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше нуля" << endl;
        return;
    }

    TimeQueue values = make_queue(n);

    cout << endl << "Исходный контейнер:" << endl;
    print_queue(values);

    cout << endl << "Поиск элемента и добавление его в конец:" << endl;
    add_element_to_end_by_key(values);
    print_queue(values);

    cout << endl << "Поиск элемента и удаление его из контейнера:" << endl;
    delete_element_by_key(values);
    print_queue(values);

    cout << endl << "Добавление среднего арифметического к каждому элементу:" << endl;
    add_average_to_all(values);
    print_queue(values);
}