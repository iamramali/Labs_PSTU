#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Vector {
    int size;
    T* data;

public:
    Vector(int s = 0, T k = T());
    Vector(const Vector<T>& v);
    ~Vector();

    Vector<T>& operator=(const Vector<T>& v);
    Vector<T> operator*(const Vector<T>& v);

    T& operator[](int index);
    operator int();

    template <class U>
    friend ostream& operator<<(ostream& out, const Vector<U>& v);

    template <class U>
    friend istream& operator>>(istream& in, Vector<U>& v);
};

template <class T>
Vector<T>::Vector(int s, T k) {
    size = s;

    if (size < 0) size = 0;

    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = k;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v) {
    size = v.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
}

template <class T>
Vector<T>::~Vector() {
    delete[] data;
    data = 0;
    size = 0;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (this == &v) return *this;

    delete[] data;

    size = v.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = v.data[i];

    return *this;
}

template <class T>
Vector<T> Vector<T>::operator*(const Vector<T>& v) {
    int limit;

    if (size < v.size) limit = size;
    else limit = v.size;

    Vector<T> temp(limit, T());

    for (int i = 0; i < limit; i++)
        temp.data[i] = data[i] * v.data[i];

    return temp;
}

template <class T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "ќшибка: индекс выходит за пределы вектора!" << endl;
        return data[0];
    }

    return data[index];
}

template <class T>
Vector<T>::operator int() {
    return size;
}

template <class U>
ostream& operator<<(ostream& out, const Vector<U>& v) {
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << " ";

    return out;
}

template <class U>
istream& operator>>(istream& in, Vector<U>& v) {
    for (int i = 0; i < v.size; i++) {
        cout << "¬ведите элемент [" << i << "]: ";
        in >> v.data[i];
    }

    return in;
}