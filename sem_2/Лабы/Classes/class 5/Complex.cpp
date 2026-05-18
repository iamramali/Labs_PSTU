#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex() : Pair(){}

Complex::Complex(int r, int i) : Pair(r, i){}

Complex::Complex(const Complex& c) : Pair(c){}

Complex::~Complex(){}

int Complex::get_real(){
    return first;
}

int Complex::get_imaginary(){
    return second;
}

void Complex::set_real(int r){
    first = r;
}

void Complex::set_imaginary(int i){
    second = i;
}

Complex& Complex::operator=(const Complex& c){
    if (this == &c) return *this;

    first = c.first;
    second = c.second;

    return *this;
}

Complex Complex::operator+(const Complex& c){
    Complex temp;

    temp.first = first + c.first;
    temp.second = second + c.second;

    return temp;
}

Complex Complex::operator-(const Complex& c){
    Complex temp;

    temp.first = first - c.first;
    temp.second = second - c.second;

    return temp;
}

Complex Complex::operator*(const Complex& c){
    Complex temp;

    temp.first = first * c.first - second * c.second;
    temp.second = first * c.second + second * c.first;

    return temp;
}

istream& operator>>(istream& in, Complex& c){
    cout << "Введите действительную часть: ";
    in >> c.first;

    cout << "Введите мнимую часть: ";
    in >> c.second;

    return in;
}

ostream& operator<<(ostream& out, const Complex& c){
    out << "Действительная часть: " << c.first << endl;
    out << "Мнимая часть: " << c.second << endl;
    out << "Комплексное число: " << c.first;

    if (c.second >= 0) out << " + " << c.second << "i" << endl;
    else out << " - " << -c.second << "i" << endl;

    return out;
}

void Complex::show(){
    cout << *this;
}