#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool isCons(char c) {
    if (tolower(c) == 'p' || tolower(c) == 'k' || tolower(c) == 'h' || tolower(c) == 'l' || tolower(c) == 'm' || tolower(c) == 'n' || tolower(c) == 'w') return true;
    return false;
}
bool isVow(char c) {
    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') return true;
    return false;
}
bool isValid(string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (isCons(str[i]) == false && isVow(str[i]) == false && str[i] != ' ' && str[i] != '\'') return false;
    }
    return true;
}
bool compareStrings(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    for (unsigned int i = 0; i<str1.length();i++) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}
bool validVowelGr(char c1, char c2) {
    string combined = string(1, tolower(c1)) + string(1, tolower(c2));
    if (compareStrings(combined, "ai") ||
        compareStrings(combined, "ae") ||
        compareStrings(combined, "ao") || 
        compareStrings(combined, "au") || 
        compareStrings(combined, "ei") || 
        compareStrings(combined, "eu") || 
        compareStrings(combined, "iu") || 
        compareStrings(combined, "oi") || 
        compareStrings(combined, "ou") || 
        compareStrings(combined, "ui")) return true;
    return false;
}
int main() {
    string s;
    getline(cin, s);
    if (isValid(s) == false) {
        cout << -1;
        return 0;
    }

    int syllableCount = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        char nextChar;
        if (i == s.length() - 1) nextChar = ' ';
        else nextChar = s[i+1];

        if(isVow(s[i])) {
            if (validVowelGr(s[i], nextChar)) {
                syllableCount++;
                i++;
            } else {
                syllableCount++;
            }
        }
    }
    cout << syllableCount;
    return 0;
}