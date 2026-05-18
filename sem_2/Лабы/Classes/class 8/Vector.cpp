#include "Vector.h"
#include "Print.h"
#include "Book.h"
#include <iostream>

using namespace std;

Vector::Vector() {
    beg = 0;
    size = 0;
    cur = 0;
}

Vector::Vector(int size) {
    this->size = size;
    cur = 0;
    beg = new Object * [size];

    for (int i = 0; i < size; i++)
        beg[i] = 0;
}

Vector::~Vector() {
    for (int i = 0; i < cur; i++)
        delete beg[i];

    delete[] beg;
    beg = 0;
}

void Vector::Add() {
    if (beg == 0) {
        cout << "Сначала создайте группу командой m <size>" << endl;
        return;
    }

    if (cur >= size) {
        cout << "Группа заполнена" << endl;
        return;
    }

    cout << "Выберите тип элемента:" << endl;
    cout << "1. Печатное издание" << endl;
    cout << "2. Книга" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    Object* object = 0;

    if (choice == 1)
        object = new Print;
    else if (choice == 2)
        object = new Book;
    else {
        cout << "Неверный номер класса" << endl;
        return;
    }

    object->Input();
    beg[cur] = object;
    cur++;
}

void Vector::Del() {
    if (cur == 0) {
        cout << "Группа пустая" << endl;
        return;
    }

    cur--;
    delete beg[cur];
    beg[cur] = 0;

    cout << "Последний элемент удален" << endl;
}

void Vector::Show() const {
    if (cur == 0) {
        cout << "Группа пустая" << endl;
        return;
    }

    cout << "Размер группы: " << size << endl;
    cout << "Количество элементов: " << cur << endl;

    for (int i = 0; i < cur; i++) {
        cout << endl << "Элемент номер " << i + 1 << endl;
        beg[i]->Show();
    }
}

void Vector::GetNameByNumber(int k) const {
    if (cur == 0) {
        cout << "Группа пустая" << endl;
        return;
    }

    if (k < 1 || k > cur) {
        cout << "Элемента с таким номером нет" << endl;
        return;
    }

    cout << "Название элемента номер " << k << ": " << beg[k - 1]->GetName() << endl;
}

int Vector::operator()() const {
    return cur;
}

void Vector::HandleEvent(const TEvent& event) {
    if (event.what != evMessage) return;

    if (event.command == cmGet)
        GetNameByNumber(event.a);
}

ostream& operator<<(ostream& out, const Vector& v) {
    v.Show();
    return out;
}