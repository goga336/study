#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <time.h> 

using namespace std;



char generateRandomLetter() {
    return 'a' + rand() % 26;
}


string generateRandomWord(int length) {
    string word;
    for (short i = 0; i < length; ++i) {
        word += generateRandomLetter();
    }
    return word;
}

int main() {
    clock_t start = clock(); // фиксация времени начала
    srand(time(NULL)); 
    short wordCount = 10;
    string randomString;

    for (short i = 0; i < wordCount; ++i) {
        short wordLength = rand() % 10 + 1;
        randomString += generateRandomWord(wordLength) + " ";
    }

    clock_t end = clock(); //фиксация времени окончания
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Сгенерированная строка: " << randomString << endl;
    cout << "Время выполнения: " << duration << " секунд" << endl;

    return 0;
}
