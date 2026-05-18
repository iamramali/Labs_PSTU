#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    char text[256], word[256];
    int len = 0, count = 0;

    cout << "Введите текст: ";
    cin.getline(text, 256, '.');

    cout << "Слова с одной цифрой: ";
    for (int i = 0; ; i++){
        if (text[i] != ' ' && text[i] != '\0'){
            word[len] = text[i];
            if (text[i] >= '0' && text[i] <= '9') count++;
            len++;
        }
        else{
            if (len > 0){
                word[len] = '\0';
                if (count == 1) cout << word << " ";
                len = 0;
                count = 0;
            }
            if (text[i] == '\0') break;
        }
    }

    cout << endl;
}
