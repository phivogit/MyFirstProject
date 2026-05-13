#include <iostream>
#include <string>
using namespace std;
int countDistinctChar1(const char str[]) {
    int charCount[300] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        charCount[c]++;
    }
    int distinctCount = 0;
    for (int i = 0; i < 300; i++) {
        if (charCount[i] > 0) {
            distinctCount++;
        }
    }
    return distinctCount;
}
int countDistinctChar2(const string &str) {
    int charCount[300] = {0};
    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        charCount[c]++;
    }
    int distinctCount = 0;
    for (int i = 0; i < 300; i++) {
        if (charCount[i] > 0) {
            distinctCount++;
        }
    }
    return distinctCount;
}

int main() {
    char str1[] = "aaaAAAAawwWwwwggggggggcccccdddd eeeEEEEEeeee fffFFFFffff";
    string str2 = "aaaaaamnmmmmmjjjjjkkkkk!@#$%^&*()";
    cout << "str1: " << countDistinctChar1(str1) << endl;
    cout << "str2: " << countDistinctChar2(str2) << endl;
}