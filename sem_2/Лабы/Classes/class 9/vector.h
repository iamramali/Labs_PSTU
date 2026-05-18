#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Vector {
public:
    Vector(int s = 0, int k = 0);
    Vector(const Vector& a);
    ~Vector();

    Vector& operator=(const Vector& a);

    int& operator[](int index);
    const int& operator[](int index) const;

    int operator()() const;

    Vector& operator--();
    Vector operator--(int);

    friend ostream& operator<<(ostream& out, const Vector& a);
    friend istream& operator>>(istream& in, Vector& a);

private:
    int size;
    int* data;
};