#include "time.h"
#include <iostream>

using namespace std;

Time::Time() {
    min = 0;
    sec = 0;
}

Time::Time(int m, int s) {
    Init(m, s);
}

Time::Time(const Time& t) {
    min = t.min;
    sec = t.sec;
}

Time::~Time() {
}

void Time::Init(int m, int s) {
    if (m < 0) throw "Минуты не могут быть отрицательными";
    if (s < 0) throw "Секунды не могут быть отрицательными";
    if (s > 60) throw "Секунд не может быть больше 60";

    min = m;
    sec = s;

    if (sec == 60) {
        min++;
        sec = 0;
    }
}

int Time::get_min() {
    return min;
}

int Time::get_sec() {
    return sec;
}

void Time::set_min(int m) {
    if (m < 0) throw "Минуты не могут быть отрицательными";

    min = m;
}

void Time::set_sec(int s) {
    if (s < 0) throw "Секунды не могут быть отрицательными";
    if (s > 60) throw "Секунд не может быть больше 60";

    sec = s;

    if (sec == 60) {
        min++;
        sec = 0;
    }
}

Time& Time::operator=(const Time& t) {
    if (&t == this) return *this;

    min = t.min;
    sec = t.sec;

    return *this;
}

bool Time::operator==(const Time& t) {
    if (min == t.min && sec == t.sec) return true;
    return false;
}

bool Time::operator!=(const Time& t) {
    if (min == t.min && sec == t.sec) return false;
    return true;
}

bool Time::operator>(const Time& t) {
    int first = min * 60 + sec;
    int second = t.min * 60 + t.sec;

    if (first > second) return true;
    return false;
}

bool Time::operator<(const Time& t) {
    int first = min * 60 + sec;
    int second = t.min * 60 + t.sec;

    if (first < second) return true;
    return false;
}

Time Time::operator+(const Time& t) {
    int first = min * 60 + sec;
    int second = t.min * 60 + t.sec;
    int result = first + second;

    Time temp(result / 60, result % 60);

    return temp;
}

Time Time::operator-(const Time& t) {
    int first = min * 60 + sec;
    int second = t.min * 60 + t.sec;

    if (first < second) throw "Нельзя получить отрицательный временной интервал";

    int result = first - second;

    Time temp(result / 60, result % 60);

    return temp;
}

istream& operator>>(istream& in, Time& t) {
    int m;
    int s;

    cout << "Минуты: ";
    in >> m;

    cout << "Секунды: ";
    in >> s;

    t.Init(m, s);

    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.min << ":";

    if (t.sec < 10) out << "0";

    out << t.sec;

    return out;
}