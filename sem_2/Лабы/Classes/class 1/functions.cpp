#include "Header.h"
#include <iostream>

using namespace std;

void Range::Init(double f, double s){
    if (f > s){
        cout << "Ошибка: левая граница больше правой!" << endl;
        exit(0);
    }

    first = f;
    second = s;
}

void Range::Read(){
    double f, s;

    cout << "Введите левую границу диапазона: ";
    cin >> f;

    cout << "Введите правую границу диапазона: ";
    cin >> s;

    Init(f, s);
}

void Range::Show(){
    cout << "Левая граница диапазона: " << first << endl;
    cout << "Правая граница диапазона: " << second << endl;
}

bool Range::check(double x){
    if (x >= first && x <= second) return true;
    else return false;
}

Range make_range(double f, double s){
    Range r;
    r.Init(f, s);
    return r;
}