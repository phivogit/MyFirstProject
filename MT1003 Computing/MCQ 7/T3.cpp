#include <iostream>

int main() {
    int r, c;
    std::cout << "R = ";
    std::cin >> r;
    std::cout << "C = ";
    std::cin >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            std::cout << " | " << i*j << " | ";
        }
        std::cout << "\n";
    }
    return 0;
}