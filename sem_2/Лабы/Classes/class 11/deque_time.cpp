#include "Tasks.h"
#include "Time.h"

#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

namespace deque_time {
    using Container = deque<Time>;

    Container make_container(int n) {
        Container c;

        for (int i = 0; i < n; i++) {
            Time value;

            cout << "Элемент времени [" << i << "]" << endl;
            cin >> value;

            c.push_back(value);
        }

        return c;
    }

    Time min_value(const Container& c) {
        return *min_element(c.begin(), c.end());
    }

    Time max_value(const Container& c) {
        return *max_element(c.begin(), c.end());
    }

    Time average(const Container& c) {
        long long sum = 0;

        for (const auto& item : c)
            sum = sum + item.total_seconds();

        return Time::from_seconds(sum / static_cast<int>(c.size()));
    }

    void add_min(Container& c, int pos) {
        c.insert(c.begin() + pos, min_value(c));
    }

    void delete_greater_than_average(Container& c) {
        Time avg = average(c);

        c.erase(remove_if(c.begin(), c.end(), [avg](const Time& value) {
            return value > avg;
            }), c.end());
    }

    void multiply_by_max(Container& c) {
        Time mx = max_value(c);

        for (auto& item : c)
            item = item * mx;
    }

    void run() {
        cout << endl << "Задача 2. Двунаправленная очередь deque<Time>" << endl;

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