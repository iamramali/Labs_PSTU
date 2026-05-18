#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Vector {
public:
    Vector();
    explicit Vector(int size);
    Vector(const Vector& other) = delete;
    virtual ~Vector();

    void Add();
    void Del();
    void Show() const;
    void GetNameByNumber(int k) const;
    int operator()() const;

    void HandleEvent(const TEvent& event);

    Vector& operator=(const Vector& other) = delete;

    friend ostream& operator<<(ostream& out, const Vector& v);

protected:
    Object** beg;
    int size;
    int cur;
};