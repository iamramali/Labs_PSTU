#pragma once
#include <iostream>

using namespace std;

class Pair{
protected:
    int first;
    int second;

public:
    Pair();
    Pair(int f, int s);
    Pair(const Pair& p);
    ~Pair();

    int get_first();
    int get_second();

    void set_first(int f);
    void set_second(int s);

    Pair& operator=(const Pair& p);
    Pair operator+(const Pair& p);

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};