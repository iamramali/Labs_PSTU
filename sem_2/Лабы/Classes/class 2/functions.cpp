#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

Number::Number(){
    mantissa = 0;
    order = 0;
    str = "0";

    cout << "Конструктор без параметров" << endl;
}

Number::Number(float m, int o, string s){
    mantissa = m;
    order = o;
    str = s;

    cout << "Конструктор с параметрами" << endl;
}

Number::Number(const Number& t){
    mantissa = t.mantissa;
    order = t.order;
    str = t.str;

    cout << "Конструктор копирования" << endl;
}

Number::~Number(){
    cout << "Деструктор" << endl;
}

float Number::get_mantissa(){
    return mantissa;
}

int Number::get_order(){
    return order;
}

string Number::get_string(){
    return str;
}

void Number::set_mantissa(float m){
    mantissa = m;
}

void Number::set_order(int o){
    order = o;
}

void Number::set_string(string s){
    str = s;
}

void Number::show(){
    cout << "Мантисса: " << mantissa << endl;
    cout << "Порядок: " << order << endl;
    cout << "Строковое представление: " << str << endl;
}