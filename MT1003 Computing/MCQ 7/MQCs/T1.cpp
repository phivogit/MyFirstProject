#include <iostream>

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int i = 1;
    do {
        std::cout << i++;
        n--;
    } while (n > 0);
    return 0;
}