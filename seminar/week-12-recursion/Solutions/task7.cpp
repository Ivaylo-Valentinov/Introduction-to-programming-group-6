#include <iostream>

void print_backwards(const char* begin, const char* end) {
    while (begin < end && (unsigned char)*begin <= 32) {
        begin++;
    }

    if (begin >= end) {
        return;
    }

    const char* w_end = begin;
    while (w_end < end && (unsigned char)*w_end > 32) {
        w_end++;
    }

    const char* next = w_end;
    bool has_next_word = false;
    while (next < end) {
        if ((unsigned char)*next > 32) {
            has_next_word = true;
            break;
        }
        next++;
    }

    print_backwards(w_end, end);

    if (has_next_word) {
        std::cout << " ";
    }

    const char* ptr = begin;
    while (ptr < w_end) {
        std::cout << *ptr;
        ptr++;
    }
}

void print_backwards(const char* string) {
    if (!string) return;

    const char* end = string;
    while (*end != '\0') {
        end++;
    }

    print_backwards(string, end);
    std::cout << std::endl;
}

int main() {
    const char* text1 = "I\tneed a break!";
    std::cout << "Вход:  \"I\\tneed a break!\"" << std::endl;
    std::cout << "Изход: ";
    print_backwards(text1);

    std::cout << "-----------------------" << std::endl;

    const char* text2 = "   Проверка   на    рекурсията!   ";
    std::cout << "Вход:  \"   Проверка   на    рекурсията!   \"" << std::endl;
    std::cout << "Изход: ";
    print_backwards(text2);

    return 0;
}
