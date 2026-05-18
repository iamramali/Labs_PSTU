#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(){
    min = 0;
    sec = 0;
}

Time::Time(int m, int s){
    if (s > 60){
        cout << "Ошибка: секунд не может быть больше 60!" << endl;
        exit(0);
    }

    min = m;
    sec = s;
}

Time::Time(const Time& t){
    min = t.min;
    sec = t.sec;
}

Time::~Time(){}

int Time::get_min(){
    return min;
}

int Time::get_sec(){
    return sec;
}

void Time::set_min(int m){
    min = m;
}

void Time::set_sec(int s){
    if (s > 60){
        cout << "Ошибка: секунд не может быть больше 60!" << endl;
        exit(0);
    }

    sec = s;
}

Time& Time::operator=(const Time& t){
    if (&t == this) return *this;

    min = t.min;
    sec = t.sec;

    return *this;
}

Time Time::operator+(int seconds){
    Time temp;

    int allSeconds = min * 60 + sec + seconds;

    temp.min = allSeconds / 60;
    temp.sec = allSeconds % 60;

    return temp;
}

bool Time::operator==(const Time& t){
    if (min == t.min && sec == t.sec) return true;
    return false;
}

bool Time::operator!=(const Time& t){
    if (min == t.min && sec == t.sec) return false;
    return true;
}

istream& operator>>(istream& in, Time& t){
    cout << "Минуты: ";
    in >> t.min;

    cout << "Секунды: ";
    in >> t.sec;

    if (t.sec > 60){
        cout << "Ошибка: секунд не может быть больше 60!" << endl;
        exit(0);
    }

    return in;
}

ostream& operator<<(ostream& out, const Time& t){
    out << t.min << " мин. " << t.sec << " сек." << endl;
    return out;
}