#include <iostream>

int main() {
    int n;
    int i = 1;
    int o = 0;
    do {
        std::cout << "\nEnter a number >= 2: ";
        std::cin >> n;
    } while (n < 2);
    do {
        if (i % 2 == 0) o+=i;
        n--;
        i++;
    } while (n > 0);
    std::cout << o;
}