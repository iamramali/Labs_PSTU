#pragma once
#include <iostream>
#include <map>

using namespace std;

template<class T>
class Vector {
    map<int, T> v;

public:
    Vector() {}

    Vector(int n);

    void Print() const;
    T Average() const;
    T Max() const;
    int NewKey() const;

    void AddMaxToEnd();
    void DeleteByKey(int key);
    void AddAverageToAll();
};

template<class T>
Vector<T>::Vector(int n) {
    T value;

    for (int i = 0; i < n; i++) {
        cout << "Элемент [" << i << "]" << endl;
        cin >> value;
        v[i] = value;
    }
}

template<class T>
void Vector<T>::Print() const {
    if (v.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    for (typename map<int, T>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << "Ключ: " << it->first << " Значение: " << it->second << endl;
}

template<class T>
T Vector<T>::Average() const {
    T sum = T();

    for (typename map<int, T>::const_iterator it = v.begin(); it != v.end(); ++it)
        sum = sum + it->second;

    return sum / static_cast<int>(v.size());
}

template<class T>
T Vector<T>::Max() const {
    typename map<int, T>::const_iterator it = v.begin();
    T mx = it->second;

    for (; it != v.end(); ++it)
        if (it->second > mx) mx = it->second;

    return mx;
}

template<class T>
int Vector<T>::NewKey() const {
    if (v.empty()) return 0;

    typename map<int, T>::const_reverse_iterator it = v.rbegin();

    return it->first + 1;
}

template<class T>
void Vector<T>::AddMaxToEnd() {
    if (v.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    T mx = Max();
    int key = NewKey();

    v[key] = mx;

    cout << "Максимальный элемент добавлен в конец контейнера" << endl;
}

template<class T>
void Vector<T>::DeleteByKey(int key) {
    if (v.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    typename map<int, T>::iterator it = v.find(key);

    if (it == v.end()) {
        cout << "Элемент с таким ключом не найден" << endl;
        return;
    }

    v.erase(it);

    cout << "Элемент удален" << endl;
}

template<class T>
void Vector<T>::AddAverageToAll() {
    if (v.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    T sr = Average();

    cout << "Среднее арифметическое = " << sr << endl;

    for (typename map<int, T>::iterator it = v.begin(); it != v.end(); ++it)
        it->second = it->second + sr;
}