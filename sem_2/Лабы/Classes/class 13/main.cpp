#include <clocale>
#include <iostream>
#include <windows.h>

using namespace std;

void task1();
void task2();
void task3();

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        cout << endl << "Лабораторная работа. Вариант 4" << endl;
        cout << "1. Задача 1: deque<Time>" << endl;
        cout << "2. Задача 2: queue<Time>" << endl;
        cout << "3. Задача 3: multimap<int, Time>" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            cout << "Работа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
        }
    } while (choice != 0);
}