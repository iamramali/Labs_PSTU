#pragma once
#include <iostream>
#include "Pair.h"

using namespace std;

class Complex : public Pair{
public:
    Complex();
    Complex(int f, int s);
    Complex(const Complex& c);
    ~Complex();

    int get_real();
    int get_imaginary();

    void set_real(int r);
    void set_imaginary(int i);

    Complex& operator=(const Complex& c);
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);

    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};