#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <time.h> 
using namespace std;

char mas[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

char generateRandomLetter() {
    int n = rand() % 52;
    for (int i = 0; i < 52; ++i) {
        if (i == n) {
            return mas[i];
        }
    }
    return 'a';
}

string generateRandomWord(int length) {
    string word;
    for (int i = 0; i < length; ++i) {
        word += generateRandomLetter();
    }
    return word;
}

int main() {
    clock_t start = clock();// фиксация времени начала
    srand(time(NULL)); 
    int wordCount = 10;
    string randomString;
    for (int i = 0; i < wordCount; ++i) {
        int wordLength = rand() % 10 + 1;
        randomString += generateRandomWord(wordLength) + " ";
    }

    clock_t end = clock(); //фиксация времени окончания
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Сгенерированная строка: " << randomString << endl;
    cout << "Время выполнения: " << duration << " секунд" << endl;

    return 0;
}
