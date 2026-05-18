#include "vector.h"
#include "error.h"

using namespace std;

Vector::Vector(int s, int k) {
    if (s < 0) throw Error(1);
    if (s > MAX_SIZE) throw Error(2);

    size = s;

    if (size == 0) data = 0;
    else data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = k;
}

Vector::Vector(const Vector& a) {
    size = a.size;

    if (size == 0) data = 0;
    else data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

Vector::~Vector() {
    delete[] data;
    data = 0;
    size = 0;
}

Vector& Vector::operator=(const Vector& a) {
    if (this == &a) return *this;

    delete[] data;

    size = a.size;

    if (size == 0) data = 0;
    else data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = a.data[i];

    return *this;
}

int& Vector::operator[](int index) {
    if (index < 0) throw Error(3);
    if (index >= size) throw Error(4);

    return data[index];
}

const int& Vector::operator[](int index) const {
    if (index < 0) throw Error(3);
    if (index >= size) throw Error(4);

    return data[index];
}

int Vector::operator()() const {
    return size;
}

Vector& Vector::operator--() {
    if (size == 0) throw Error(5);

    int newSize = size - 1;
    int* temp;

    if (newSize == 0) temp = 0;
    else temp = new int[newSize];

    for (int i = 0; i < newSize; i++)
        temp[i] = data[i + 1];

    delete[] data;

    data = temp;
    size = newSize;

    return *this;
}

Vector Vector::operator--(int) {
    if (size == 0) throw Error(5);

    Vector old(*this);

    int newSize = size - 1;
    int* temp;

    if (newSize == 0) temp = 0;
    else temp = new int[newSize];

    for (int i = 0; i < newSize; i++)
        temp[i] = data[i];

    delete[] data;

    data = temp;
    size = newSize;

    return old;
}

ostream& operator<<(ostream& out, const Vector& a) {
    if (a.size == 0) {
        out << "Вектор пустой";
        return out;
    }

    for (int i = 0; i < a.size; i++)
        out << a.data[i] << " ";

    return out;
}

istream& operator>>(istream& in, Vector& a) {
    for (int i = 0; i < a.size; i++) {
        cout << "Введите элемент [" << i << "]: ";
        in >> a.data[i];
    }

    return in;
}