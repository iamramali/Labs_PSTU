#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

void printArray(int a[], int n){
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    setlocale(LC_ALL, "");
    srand((unsigned)time(0));

    
    int a[10], b[10], n = 10;

    for (int i = 0; i < n; i++) a[i] = rand() % 41 - 20;

    cout << "Исходный массив:" << endl;
    printArray(a, n);

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) a[k++] = a[i];
    }
    n = k;
    cout << "После удаления элементов с индексами, кратными 3:" << endl;
    printArray(a, n);

    k = 0;
    for (int i = 0; i < n; i++){
        b[k++] = a[i];
        if (a[i] < 0){
            int ind = abs(i - 1) + 1;
            if (ind >= n) ind = n - 1;
            b[k++] = a[ind];
        }
    }

    cout << "После добавления элемента M[|i - 1| + 1] после каждого отрицательного:" << endl;
    printArray(b, k);
}
