#pragma once
#include <iostream>

using namespace std;

class Range {
    double first;
    double second;
public:
    void Init(double f, double s);
    void Read();
    void Show();
    bool check(double x);
};

Range make_range(double f, double s);