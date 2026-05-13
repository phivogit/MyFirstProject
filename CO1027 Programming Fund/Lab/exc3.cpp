#include <iostream>
#include <string>
using namespace std;
void longestWord(const char str[], char result[]) {
    int max = 0;
    int start = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            int length = i - start;
            if (length > max) {
                max = length;
                for (int j = 0; j < length; j++) {
                    result[j] = str[start + j];
                }
            }
            start = i + 1;
        }
    }
};


string longestWord(const string &str) {
    string longest = "";
    int start = 0;
    for (size_t i = 0; i <= str.length(); i++) {
        if (i == str.length() || str[i] == ' ') {
            string word = str.substr(start, i - start);
            if (word.length() > longest.length()) {
                longest = word;
            }
            start = i + 1;
        }
    }
    return longest;
}
int main() {
    char str1[] = "HELLO MAY BE I CAN HELP YOU";
    string str2 = "HELLO THEAW MAY BE I CAN HELP YOU";
    char result[100];
    longestWord(str1, result);
    cout << "Longest word in str1: " << result;
    cout << "Longest word in str2: " << longestWord(str2);
}