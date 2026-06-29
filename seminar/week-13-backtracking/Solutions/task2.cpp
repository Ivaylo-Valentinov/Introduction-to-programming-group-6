#include <iostream>

void generateRecursive(const char alphabet[], int alphabetSize, char currentWord[], int n, int index) {
    if (index == n) {
        currentWord[n] = '\0';
        std::cout << currentWord << std::endl;
        return;
    }

    for (int i = 0; i < alphabetSize; i++) {
        currentWord[index] = alphabet[i];
        generateRecursive(alphabet, alphabetSize, currentWord, n, index + 1);
    }
}

void printWordsOfLength(const char alphabet[], int alphabetSize, int n) {
    if (n <= 0) {
        return;
    }
    
    char* wordBuffer = new char[n + 1];
    generateRecursive(alphabet, alphabetSize, wordBuffer, n, 0);
    delete[] wordBuffer;
}

int main() {
    // Дефинираме примерна азбука от символи
    char alphabet[] = {'a', 'b', 'c'};
    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);

    int m;
    std::cout << "Въведете m: ";
    std::cin >> m;

    std::cout << "Всички думи с дължина, по-малка от " << m << ":" << std::endl;
    
    // Цикълът обхожда всички възможни дължини от 1 до m - 1
    for (int len = 1; len < m; len++) {
        printWordsOfLength(alphabet, alphabetSize, len);
    }

    return 0;
}
