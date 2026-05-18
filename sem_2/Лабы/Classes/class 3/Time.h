#pragma once
#include <iostream>

using namespace std;

class Time
{
    int min;
    int sec;

public:
    Time();
    Time(int m, int s);
    Time(const Time& t);
    ~Time();

    int get_min();
    int get_sec();

    void set_min(int m);
    void set_sec(int s);

    Time& operator=(const Time& t);
    Time operator+(int seconds);

    bool operator==(const Time& t);
    bool operator!=(const Time& t);

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};