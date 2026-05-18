#include "Print.h"
#include <iostream>

using namespace std;

Print::Print() {
    name = "";
    author = "";
}

Print::Print(const string& name, const string& author) {
    this->name = name;
    this->author = author;
}

Print::Print(const Print& other) {
    name = other.name;
    author = other.author;
}

void Print::Show() const {
    cout << "Название: " << name << endl;
    cout << "Автор: " << author << endl;
}

void Print::Input() {
    cout << "Название: ";
    getline(cin >> ws, name);

    cout << "Автор: ";
    getline(cin >> ws, author);
}

void Print::HandleEvent(const TEvent& event) {
    if (event.what == evMessage && event.command == cmGet)
        cout << "Название: " << name << endl;
}

const char* Print::GetName() const {
    return name.c_str();
}

string Print::get_name() const {
    return name;
}

string Print::get_author() const {
    return author;
}

void Print::set_name(string name) {
    this->name = name;
}

void Print::set_author(string author) {
    this->author = author;
}

Print& Print::operator=(const Print& other) {
    if (this == &other) return *this;

    name = other.name;
    author = other.author;

    return *this;
}