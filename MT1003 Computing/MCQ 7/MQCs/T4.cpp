#include <iostream>

int main() {
    int h, w;
    std::cout << "H = ";
    std::cin >> h;
    std::cout << "W = ";
    std::cin >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <=w; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}