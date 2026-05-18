#include "Tasks.h"
#include "Time.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

namespace klass_queue_time {
    template <class T>
    class Vector {
    public:
        Vector() {
        }

        explicit Vector(int n) {
            for (int i = 0; i < n; i++) {
                T value;

                cout << "Элемент [" << i << "]" << endl;
                cin >> value;

                q.push(value);
            }
        }

        void Print() const {
            vector<T> values = ToVector();
            print_container(values);
        }

        T Min() const {
            vector<T> values = ToVector();
            return *min_element(values.begin(), values.end());
        }

        T Max() const {
            vector<T> values = ToVector();
            return *max_element(values.begin(), values.end());
        }

        T Average() const {
            vector<T> values = ToVector();
            T sum;

            for (const auto& item : values)
                sum = sum + item;

            return sum / static_cast<int>(values.size());
        }

        void AddMin(int pos) {
            vector<T> values = ToVector();

            values.insert(values.begin() + pos, Min());

            FromVector(values);
        }

        void DeleteGreaterThanAverage() {
            vector<T> values = ToVector();
            T avg = Average();

            values.erase(remove_if(values.begin(), values.end(), [avg](const T& item) {
                return item > avg;
                }), values.end());

            FromVector(values);
        }

        void MultiplyByMax() {
            vector<T> values = ToVector();
            T mx = Max();

            for (auto& item : values)
                item = item * mx;

            FromVector(values);
        }

        size_t Size() const {
            return q.size();
        }

    private:
        queue<T> q;

        vector<T> ToVector() const {
            queue<T> copy = q;
            vector<T> values;

            while (!copy.empty()) {
                values.push_back(copy.front());
                copy.pop();
            }

            return values;
        }

        void FromVector(const vector<T>& values) {
            queue<T> fresh;

            for (const auto& item : values)
                fresh.push(item);

            q = fresh;
        }
    };

    void run() {
        cout << endl << "Задача 5. Параметризованный класс Vector<Time> на основе queue" << endl;

        Vector<Time> v(read_positive_size());

        cout << "Исходная очередь: ";
        v.Print();

        v.AddMin(read_position(v.Size()));

        cout << "После добавления минимального элемента: ";
        v.Print();

        v.DeleteGreaterThanAverage();

        cout << "После удаления элементов больше среднего: ";
        v.Print();

        v.MultiplyByMax();

        cout << "После умножения каждого элемента на максимальный: ";
        v.Print();
    }
}