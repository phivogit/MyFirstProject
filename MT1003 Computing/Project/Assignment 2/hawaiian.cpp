#include <iostream>
#include <string>
using namespace std;

string vowelToSound(char vow) {
    if (vow == 'a') return "ah";
    else if (vow == 'e') return "eh";
    else if (vow == 'i') return "ee";
    else if (vow == 'o') return "oh";
    else if (vow == 'u') return "oo";
    else cout << "Not a vowel";
}
string vowelGroupToSound(char vow1, char vow2) {
    string vowGr = string(1,vow1) + string(1,vow2);
    if (vowGr == "ai" || vowGr == "ae") return "eye";
    else if (vowGr == "ao" || vowGr == "au" || vowGr == "ou") return "ow";
    else if (vowGr == "ei") return "ay";
    else if (vowGr == "eu") return "eh-oo";
    else if (vowGr == "iu") return "ew";
    else if (vowGr == "oi") return "oy";
    else if (vowGr == "ui") return "ooey";
    else return vowelToSound(vow1) + "-" + vowelToSound(vow2);
}
int main() {
    string inpstr;
    string resultstr = "";
    getline(cin, inpstr);
    
    char possibleConsonants[7] = {'p', 'k', 'h', 'l', 'm', 'n', 'w'};
    char possibleVowels[5]= {'a', 'e', 'i', 'o', 'u'};

    bool afterConsonant;
    for (char letter : inpstr) {
        auto fnd1 = find(begin(possibleConsonants), end(possibleConsonants), letter);
        auto fnd2 = find(begin(possibleVowels), end(possibleVowels), letter);
        if (fnd1 == end(possibleConsonants) || fnd2 == end(possibleConsonants)) {
            cout << "Invalid hawaiian string";
            return 0;
        }
        if (fnd2 != end(possibleConsonants)) {
            auto nextfnd = find(begin(possibleVowels), end(possibleVowels), letter+1);
            if (nextfnd != end(possibleVowels))  
        }

    }
}