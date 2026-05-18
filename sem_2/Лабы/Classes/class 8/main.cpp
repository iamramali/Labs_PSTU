#include "Dialog.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Команды:" << endl;
    cout << "m <size>  - создание группы" << endl;
    cout << "+         - добавление элемента" << endl;
    cout << "-         - удаление последнего элемента" << endl;
    cout << "s         - вывод всей группы" << endl;
    cout << "z <k>     - вывод названия элемента с номером k" << endl;
    cout << "q         - выход" << endl;

    Dialog dialog;
    dialog.Execute();
}