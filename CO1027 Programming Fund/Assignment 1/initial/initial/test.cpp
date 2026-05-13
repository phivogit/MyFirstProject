#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream inpFile("opw_tc_01_input");
    string text;
    getline(inpFile, text);
    const int FIXED_CHARACTER = 7;
    int tempListIndex2[FIXED_CHARACTER - 2] = {-1};
    for (int i = 0; i<FIXED_CHARACTER -2; i++) cout << tempListIndex2[i];
}