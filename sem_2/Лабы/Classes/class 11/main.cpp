#include <iostream>
#include <clocale>
#include "Tasks.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        cout << endl;
        cout << "1. Задача 1: deque<int>" << endl;
        cout << "2. Задача 2: deque<Time>" << endl;
        cout << "3. Задача 3: параметризованный класс Vector на основе vector" << endl;
        cout << "4. Задача 4: адаптер queue<Time>" << endl;
        cout << "5. Задача 5: параметризованный класс Vector на основе queue" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                deque_int::run();
                break;
            case 2:
                deque_time::run();
                break;
            case 3:
                vector_time::run();
                break;
            case 4:
                queue_time::run();
                break;
            case 5:
                klass_queue_time::run();
                break;
            case 0:
                cout << "Завершение программы" << endl;
                break;
            default:
                cout << "Такого пункта меню нет" << endl;
                break;
            }
        }
        catch (const exception& error) {
            cout << "Ошибка: " << error.what() << endl;
        }
    } while (choice != 0);
}