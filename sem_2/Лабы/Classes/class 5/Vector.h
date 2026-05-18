#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Vector
{
    Object** beg;
    int size;
    int cur;

public:
    Vector();
    Vector(int n);
    ~Vector();

    void Add(Object* p);

    friend ostream& operator<<(ostream& out, const Vector& v);
};