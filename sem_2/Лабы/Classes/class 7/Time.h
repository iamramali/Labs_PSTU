#pragma once
#include <iostream>

using namespace std;

class Time {
    int min;
    int sec;

public:
    Time();
    Time(int m, int s);
    Time(const Time& t);
    ~Time();

    Time& operator=(const Time& t);
    Time operator*(const Time& t);

    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& in, Time& t);
};