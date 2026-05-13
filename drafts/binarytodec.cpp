#include <iostream>
#include <cstring>

int binaryToDecimal(const char* str) {
    int decimal = 0;
    int i = 0;
    while (str[i] != '\0') {
        decimal = decimal *2 + (str[i] - '0');
        i++;
    }
    return decimal;
}

int main() {
    char str[100];
    std::cin >> str;
    std::cout << binaryToDecimal(str);
}