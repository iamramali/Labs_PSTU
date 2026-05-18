#include "Tasks.h"

#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>

using namespace std;

namespace deque_int {
    using Container = deque<int>;

    Container make_container(int n) {
        Container c;

        for (int i = 0; i < n; i++) {
            int value;

            cout << "Элемент [" << i << "] = ";
            cin >> value;

            c.push_back(value);
        }

        return c;
    }

    int min_value(const Container& c) {
        return *min_element(c.begin(), c.end());
    }

    int max_value(const Container& c) {
        return *max_element(c.begin(), c.end());
    }

    double average(const Container& c) {
        int sum = accumulate(c.begin(), c.end(), 0);
        return static_cast<double>(sum) / c.size();
    }

    void add_min(Container& c, int pos) {
        c.insert(c.begin() + pos, min_value(c));
    }

    void delete_greater_than_average(Container& c) {
        double avg = average(c);

        c.erase(remove_if(c.begin(), c.end(), [avg](int value) {
            return value > avg;
            }), c.end());
    }

    void multiply_by_max(Container& c) {
        int mx = max_value(c);

        for (auto& item : c)
            item = item * mx;
    }

    void run() {
        cout << endl << "Задача 1. Двунаправленная очередь deque<int>" << endl;

        Container c = make_container(read_positive_size());

        cout << "Исходная очередь: ";
        print_container(c);

        add_min(c, read_position(c.size()));

        cout << "После добавления минимального элемента: ";
        print_container(c);

        delete_greater_than_average(c);

        cout << "После удаления элементов больше среднего: ";
        print_container(c);

        multiply_by_max(c);

        cout << "После умножения каждого элемента на максимальный: ";
        print_container(c);
    }
}