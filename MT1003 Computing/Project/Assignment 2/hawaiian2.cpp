#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void toLowerString(string& str) {
    for (char& letter : str) {
        letter = tolower(letter);
    }
}
bool isConsonant(char letter) {
    char possibleConsonants[14] = {'p', 'k', 'h', 'l', 'm', 'n', 'w', 'P', 'K', 'H', 'L', 'M', 'N', 'W'};
    for (char c : possibleConsonants) {
        if (letter == c) return true;
    }
    return false;
}
bool isVowel(char letter) {
    char possibleVowels[10]= {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (char v : possibleVowels) {
        if (letter == v) return true;
    }
    return false;
}
bool isValid(string str) {
    for (char letter : str) {
        if (!isConsonant(letter) && !isVowel(letter) && letter != ' ' && letter != '\'') {
            return false;
        }
    }
    return true;
}
string vowelToSound(char vow) {
    if (vow == 'a') return "ah";
    else if (vow == 'e') return "eh";
    else if (vow == 'i') return "ee";
    else if (vow == 'o') return "oh";
    else if (vow == 'u') return "oo";
    return "";
}
string vowelGroupToSound(char vow1, char vow2) {
    string vowGr = string(1,vow1) + string(1,vow2);
    string returnString = "";
    if (vowGr == "ai" || vowGr == "ae") returnString += "eye";
    else if (vowGr == "ao" || vowGr == "au" || vowGr == "ou") returnString += "ow";
    else if (vowGr == "ei") returnString += "ay";
    else if (vowGr == "eu") returnString += "eh-oo";
    else if (vowGr == "iu") returnString += "ew";
    else if (vowGr == "oi") returnString += "oy";
    else if (vowGr == "ui") returnString += "ooey";
    return returnString;
}
int main() {
    string word;
    getline(cin, word);
    string resultstr = "";
    if (!isValid(word))
    {
        cout << word + " contains invalid characters.";
        return 0;
    }
    toLowerString(word);
    for (unsigned int i = 0; i < word.length(); i++) {
        if (isConsonant(word[i])) {
            char prevChar;
            if (i == 0) prevChar = ' ';
            else prevChar = word[i-1];
            if (word[i] == 'w' && (prevChar == 'i' || prevChar == 'e')) resultstr+="v";
            else resultstr += string(1, word[i]);
        } else if (isVowel(word[i])) {
            char nextChar;
            if (i == word.length() - 1) nextChar = ' ';
            else nextChar = word[i+1];
            if (isVowel(nextChar)) {
                string vowelGroup = "";
                vowelGroup += vowelGroupToSound(word[i], nextChar);
                if (vowelGroup == "") resultstr += vowelToSound(word[i]);
                else {
                    resultstr += vowelGroup;
                    i++;
                }
            } else {
                resultstr += vowelToSound(word[i]);
            }
            if (i != word.length()-1 && word[i+1] != ' ' && word[i+1] != '\'') resultstr += "-";
        }
        else if (word[i] == ' ' || word[i] == '\'')
        {
            resultstr += string(1, word[i]);
        }
    }
    cout << resultstr;
    return 0;
}