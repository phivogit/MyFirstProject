#include <iostream>
using namespace std;
int main() {
    double ele;
    double price;
    cout << "Nhap so dien tieu thu: ";
    cin >> ele;
    if (ele > 0 && ele <= 50) price = 1.678;
    else if (ele > 50 && ele <= 100) price = 1.734;
    else if (ele > 100 && ele <= 200) price = 2.014;
    else if (ele > 200 && ele <= 300) price = 2.536;
    else if (ele > 300) price = 2.834;
    else {cout << "So dien tieu thu khong hop le"; return 0;}
    cout << "Tien dien: " << ele * price << " VND";
}