#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int size = 5;
    int nums[size] = { 74,23,8,24,1 };

    for (int i = 1; i < size; i++) {
        int num = nums[i];
        int pos = i - 1;

        while (pos >= 0 && nums[pos] > num) {
            nums[pos + 1] = nums[pos];
            pos--;
        }

        nums[pos + 1] = num;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) cout << nums[i] << " ";
    cout << endl;
}
