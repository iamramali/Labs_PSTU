#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number {
    float mantissa;
    int order;
    string str;

public:
    Number();
    Number(float m, int o, string s);
    Number(const Number& t);
    ~Number();

    float get_mantissa();
    int get_order();
    string get_string();

    void set_mantissa(float m);
    void set_order(int o);
    void set_string(string s);

    void show();
};