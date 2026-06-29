#include <iostream>

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 6;
    
    std::cout << n << "! = " << factorial(n) << std::endl;
    std::cout << n << "-тото число на Фибоначи е: " << fibonacci(n) << std::endl;
    
    return 0;
}
