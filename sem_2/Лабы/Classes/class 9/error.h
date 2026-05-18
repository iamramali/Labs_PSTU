#pragma once
#include <string>

using namespace std;

class Error {
public:
    Error(int code) {
        switch (code) {
        case 1:
            message = "Ошибка: размер вектора не может быть отрицательным";
            break;
        case 2:
            message = "Ошибка: размер вектора больше MAX_SIZE";
            break;
        case 3:
            message = "Ошибка: индекс меньше нуля";
            break;
        case 4:
            message = "Ошибка: индекс выходит за границы вектора";
            break;
        case 5:
            message = "Ошибка: нельзя удалить элемент из пустого вектора";
            break;
        default:
            message = "Неизвестная ошибка";
            break;
        }
    }

    const string& what() const {
        return message;
    }

private:
    string message;
};