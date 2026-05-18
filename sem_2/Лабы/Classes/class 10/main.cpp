#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "time.h"

using namespace std;

void CopyFile(string from, string to) {
    ifstream file1(from);
    ofstream file2(to);

    if (!file1 || !file2) throw "Ошибка открытия файла";

    Time t;

    while (file1 >> t)
        file2 << t << endl;

    file1.close();
    file2.close();
}

void CreateFile() {
    ofstream file("text.txt");

    if (!file) throw "Ошибка открытия файла";

    int n;

    cout << "Введите количество записей: ";
    cin >> n;

    if (n <= 0) throw "Количество записей должно быть больше нуля";

    for (int i = 0; i < n; i++) {
        Time t;

        cout << "Введите запись номер " << i + 1 << endl;
        cin >> t;

        file << t << endl;
    }

    file.close();

    cout << "Файл создан" << endl;
}

void PrintFile() {
    ifstream file("text.txt");

    if (!file) throw "Файл не найден";

    Time t;
    int number = 1;
    bool empty = true;

    cout << "Содержимое файла:" << endl;

    while (file >> t) {
        cout << number << ". " << t << endl;
        number++;
        empty = false;
    }

    if (empty) cout << "Файл пуст" << endl;

    file.close();
}

void DeleteFromInterval() {
    ifstream file("text.txt");

    if (!file) throw "Файл не найден";

    ofstream temp("temp.txt");

    if (!temp) throw "Ошибка открытия временного файла";

    Time k1;
    Time k2;
    Time t;

    cout << "Введите начало интервала k1:" << endl;
    cin >> k1;

    cout << "Введите конец интервала k2:" << endl;
    cin >> k2;

    if (k1 > k2) throw "Ошибка: k1 не может быть больше k2";

    while (file >> t)
        if (t < k1 || t > k2)
            temp << t << endl;

    file.close();
    temp.close();

    CopyFile("temp.txt", "text.txt");

    cout << "Записи из заданного интервала удалены" << endl;
}

void AddOneMinuteThirtySeconds() {
    ifstream file("text.txt");

    if (!file) throw "Файл не найден";

    ofstream temp("temp.txt");

    if (!temp) throw "Ошибка открытия временного файла";

    Time value;
    Time add(1, 30);
    Time t;

    cout << "Введите значение, которое нужно увеличить на 1 минуту 30 секунд:" << endl;
    cin >> value;

    while (file >> t) {
        if (t == value)
            t = t + add;

        temp << t << endl;
    }

    file.close();
    temp.close();

    CopyFile("temp.txt", "text.txt");

    cout << "Все подходящие записи увеличены на 1 минуту 30 секунд" << endl;
}

void AddKToBegin() {
    ifstream file("text.txt");

    if (!file) throw "Файл не найден";

    ofstream temp("temp.txt");

    if (!temp) throw "Ошибка открытия временного файла";

    int k;

    cout << "Введите количество записей для добавления в начало файла: ";
    cin >> k;

    if (k <= 0) throw "Количество добавляемых записей должно быть больше нуля";

    for (int i = 0; i < k; i++) {
        Time t;

        cout << "Введите новую запись номер " << i + 1 << endl;
        cin >> t;

        temp << t << endl;
    }

    Time t;

    while (file >> t)
        temp << t << endl;

    file.close();
    temp.close();

    CopyFile("temp.txt", "text.txt");

    cout << "Записи добавлены в начало файла" << endl;
}

void Menu() {
    cout << endl;
    cout << "1. Создать файл" << endl;
    cout << "2. Просмотреть файл" << endl;
    cout << "3. Удалить записи из интервала от k1 до k2" << endl;
    cout << "4. Увеличить заданные записи на 1 минуту 30 секунд" << endl;
    cout << "5. Добавить K записей в начало файла" << endl;
    cout << "0. Выход" << endl;
    cout << "Ваш выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        try {
            Menu();
            cin >> choice;

            switch (choice) {
            case 1:
                CreateFile();
                break;
            case 2:
                PrintFile();
                break;
            case 3:
                DeleteFromInterval();
                break;
            case 4:
                AddOneMinuteThirtySeconds();
                break;
            case 5:
                AddKToBegin();
                break;
            case 0:
                cout << "Завершение программы" << endl;
                break;
            default:
                cout << "Такого пункта меню нет" << endl;
                break;
            }
        }
        catch (const char* error) {
            cout << error << endl;
        }
    } while (choice != 0);
}