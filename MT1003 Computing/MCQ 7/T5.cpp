#include <iostream>

int main() {
    int n;
    do {
        std::cout << "Enter N (1 <= N <= 9): ";
        std::cin >> n;
    } while (n < 1 || n > 9);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j;
        }
        std::cout << "\n";
    }
}