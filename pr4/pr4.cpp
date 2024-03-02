#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

string reverse(const string& word) {
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

string removeVowels(const string& word) {
    string result;
    for (char tt : word) {
        if (string("aeiouAEIOU").find(tt) == string::npos) {
            result += tt;
        }
    }
    return result;
}

string removeConsonants(const string& word) {
    string result;
    for (char ch : word) {
        if (string("aeiouAEIOU").find(ch) != string::npos) {
            result += ch;
        }
    }
    return result;
}

string shuffle(const string& word) {
    string shuffledWord = word;
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(shuffledWord.begin(), shuffledWord.end(), default_random_engine(seed));
    return shuffledWord;
}

int main() {

    setlocale(LC_ALL, "RUS");
    string word;
    int choice;

    cout << "Введите слово: ";
    cin >> word;

    cout << "Выберите действие:\n"
        << "1. Слово выводится задом наперед.\n"
        << "2. Вывести слово без гласных.\n"
        << "3. Вывести слово без согласных.\n"
        << "4. Рандомно раскидывать буквы заданного слова.\n"
        << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Реверсированное слово: " << reverse(word) << endl;
        break;
    case 2:
        cout << "Слово без гласных: " << removeVowels(word) << endl;
        break;
    case 3:
        cout << "Слово без согласных: " << removeConsonants(word) << endl;
        break;
    case 4:
        cout << "Перемешанное слово: " << shuffle(word) << endl;
        break;
    default:
        cout << "Неверный выбор." << endl;
    }

    return 0;
}
