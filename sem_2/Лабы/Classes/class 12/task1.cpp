#include <iostream>
#include <map>

using namespace std;

typedef map<int, int> TMapInt;

TMapInt make_map_int(int n) {
    TMapInt m;
    int value;

    for (int i = 0; i < n; i++) {
        cout << "Элемент [" << i << "]: ";
        cin >> value;
        m[i] = value;
    }

    return m;
}

void print_map_int(const TMapInt& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    for (TMapInt::const_iterator it = m.begin(); it != m.end(); ++it)
        cout << "Ключ: " << it->first << " Значение: " << it->second << endl;
}

int max_value_int(const TMapInt& m) {
    TMapInt::const_iterator it = m.begin();
    int mx = it->second;

    for (; it != m.end(); ++it)
        if (it->second > mx) mx = it->second;

    return mx;
}

int average_int(const TMapInt& m) {
    int sum = 0;

    for (TMapInt::const_iterator it = m.begin(); it != m.end(); ++it)
        sum = sum + it->second;

    return sum / static_cast<int>(m.size());
}

int new_key_int(const TMapInt& m) {
    if (m.empty()) return 0;

    TMapInt::const_reverse_iterator it = m.rbegin();

    return it->first + 1;
}

void add_max_to_end_int(TMapInt& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    int mx = max_value_int(m);
    int key = new_key_int(m);

    m[key] = mx;

    cout << "Максимальный элемент добавлен в конец контейнера" << endl;
}

void delete_by_key_int(TMapInt& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    int key;

    cout << "Введите ключ для удаления: ";
    cin >> key;

    TMapInt::iterator it = m.find(key);

    if (it == m.end()) {
        cout << "Элемент с таким ключом не найден" << endl;
        return;
    }

    m.erase(it);

    cout << "Элемент удален" << endl;
}

void add_average_to_all_int(TMapInt& m) {
    if (m.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    int sr = average_int(m);

    cout << "Среднее арифметическое = " << sr << endl;

    for (TMapInt::iterator it = m.begin(); it != m.end(); ++it)
        it->second = it->second + sr;
}

void task1() {
    int n;

    cout << "Количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше нуля" << endl;
        return;
    }

    TMapInt m = make_map_int(n);

    cout << endl << "Исходный контейнер:" << endl;
    print_map_int(m);

    cout << endl << "Добавление максимального элемента в конец контейнера:" << endl;
    add_max_to_end_int(m);
    print_map_int(m);

    cout << endl << "Удаление элемента по ключу:" << endl;
    delete_by_key_int(m);
    print_map_int(m);

    cout << endl << "Добавление среднего арифметического ко всем элементам:" << endl;
    add_average_to_all_int(m);
    print_map_int(m);
}