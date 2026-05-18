#include "Pair.h"
#include <iostream>

using namespace std;

Pair::Pair(){
    first = 0;
    second = 0;
}

Pair::Pair(int f, int s){
    first = f;
    second = s;
}

Pair::Pair(const Pair& p){
    first = p.first;
    second = p.second;
}

Pair::~Pair(){}

int Pair::get_first(){
    return first;
}

int Pair::get_second(){
    return second;
}

void Pair::set_first(int f){
    first = f;
}

void Pair::set_second(int s){
    second = s;
}

Pair& Pair::operator=(const Pair& p){
    if (this == &p) return *this;

    first = p.first;
    second = p.second;

    return *this;
}

Pair Pair::operator+(const Pair& p){
    Pair temp;

    temp.first = first + p.first;
    temp.second = second + p.second;

    return temp;
}

istream& operator>>(istream& in, Pair& p){
    cout << "Введите первое число: ";
    in >> p.first;

    cout << "Введите второе число: ";
    in >> p.second;

    return in;
}

ostream& operator<<(ostream& out, const Pair& p){
    out << "Первое число: " << p.first << endl;
    out << "Второе число: " << p.second << endl;

    return out;
}

void Pair::show(){
    cout << *this;
}