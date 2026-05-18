#include <iostream>

using namespace std;
const int SIZE = 10;


void deleteRow(int mas[SIZE][SIZE], int& n, int m, int row){
    for (int i = row; i < n - 1; i++)
        for (int j = 0; j < m; j++) mas[i][j] = mas[i + 1][j];

    for (int j = 0; j < m; j++) mas[n - 1][j] = 0;

    n--;
}

void deleteRows(int mas[SIZE][SIZE], int& n, int m, int a, int b){
    int count = b - a + 1;
    for (int i = 0; i < count; i++) deleteRow(mas, n, m, a);
}

int main(){
    setlocale(LC_ALL, "Russian");

    int mas[SIZE][SIZE];
    int n, m, a, b, oldN;

    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    oldN = n;

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mas[i][j];

    cout << "Введите номера строк A и B: ";
    cin >> a >> b;

    deleteRows(mas, n, m, a - 1, b - 1);

    cout << "Полученный массив:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cout << mas[i][j] << " ";
        cout << endl;
    }

}
