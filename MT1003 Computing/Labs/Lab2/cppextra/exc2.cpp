#include <iostream>
using namespace std;
int main() {
    double income;
    cout << "Nhap thu nhap thang (trieu VND): ";
    cin >> income;
    double tax;
    if (income <= 5) tax = 0;
    else if (income <= 10) tax = income * 0.05;
    else if (income <= 18) tax = income * 0.1;
    else if (income <= 32) tax = income * 0.15;
    else if (income <= 52) tax = income * 0.2;
    else if (income <= 80) tax = income * 0.25;
    else tax = income * 0.3;
    cout << "Thue phai nop: " << tax << " trieu VND";
}