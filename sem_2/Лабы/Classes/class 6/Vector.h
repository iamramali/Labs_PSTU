#pragma once
#include <iostream>

using namespace std;

class Vector {
public:
    class Iterator {
        friend class Vector;

    public:
        Iterator();
        Iterator(const Iterator& it);

        int& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        Iterator operator-(int n);

    private:
        int* elem;
    };

    Vector(int s = 0, int k = 0);
    Vector(const Vector& v);
    ~Vector();

    Vector& operator=(const Vector& v);

    int& operator[](int index);
    int operator()();

    Vector operator*(int number);

    Iterator first();
    Iterator last();

    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);

private:
    int size;
    int* data;
};