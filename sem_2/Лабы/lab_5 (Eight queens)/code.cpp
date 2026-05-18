#include <iostream>
#include <locale.h>

using namespace std;

const int n = 8;
int desk[n][n];
int number = 0;

void printDesk() {
    cout << "Решение " << number++ << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (desk[i][j] ? "Ф " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool canPut(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (desk[i][col]) return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (desk[i][j]) return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (desk[i][j]) return false;
    }

    return true;
}

void putQueen(int row) {
    if (row == n) {
        printDesk();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (canPut(row, col)) {
            desk[row][col] = 1;
            putQueen(row + 1);
            desk[row][col] = 0;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    putQueen(0);
    cout << "Всего решений: " << number << endl;
}
