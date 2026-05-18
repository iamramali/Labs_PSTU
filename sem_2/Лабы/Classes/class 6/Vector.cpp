#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Iterator::Iterator() {
    elem = 0;
}

Vector::Iterator::Iterator(const Iterator& it) {
    elem = it.elem;
}

int& Vector::Iterator::operator*() {
    return *elem;
}

Vector::Iterator& Vector::Iterator::operator++() {
    elem++;
    return *this;
}

Vector::Iterator Vector::Iterator::operator++(int) {
    Iterator temp(*this);
    elem++;
    return temp;
}

Vector::Iterator Vector::Iterator::operator-(int n) {
    Iterator temp(*this);
    temp.elem = temp.elem - n;
    return temp;
}

Vector::Vector(int s, int k) {
    size = s;

    if (size < 0) size = 0;

    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = k;
}

Vector::Vector(const Vector& v) {
    size = v.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
}

Vector::~Vector() {
    delete[] data;
    data = 0;
    size = 0;
}

Vector& Vector::operator=(const Vector& v) {
    if (this == &v) return *this;

    delete[] data;

    size = v.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = v.data[i];

    return *this;
}

int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "ќшибка: индекс выходит за пределы вектора!" << endl;
        return data[0];
    }

    return data[index];
}

int Vector::operator()() {
    return size;
}

Vector Vector::operator*(int number) {
    Vector temp(size);

    for (int i = 0; i < size; i++)
        temp.data[i] = data[i] * number;

    return temp;
}

Vector::Iterator Vector::first() {
    Iterator temp;
    temp.elem = data;
    return temp;
}

Vector::Iterator Vector::last() {
    Iterator temp;
    temp.elem = data + size - 1;
    return temp;
}

ostream& operator<<(ostream& out, const Vector& v) {
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << " ";

    return out;
}

istream& operator>>(istream& in, Vector& v) {
    for (int i = 0; i < v.size; i++) {
        cout << "¬ведите элемент [" << i << "]: ";
        in >> v.data[i];
    }

    return in;
}