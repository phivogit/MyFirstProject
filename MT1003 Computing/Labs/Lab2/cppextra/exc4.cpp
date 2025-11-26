#include <iostream>
using namespace std;
int main() {
    cout << "Nhap gio, phut, giay: ";
    int gio , phut, giay;
    cin >> gio >> phut >> giay;
    if (gio < 0 || gio > 23 || phut < 0 || phut > 59 || giay < 0 || giay > 59) {
        cout << "Thoi gian khong hop le";
        return 0;
    }
    int tgio = 24-gio;
    int tphut = 60-phut;
    int tgiay = 60-giay;
    if (tgiay == 60) {
        tgiay = 0;
        tphut += 1;
    }
    if (tphut == 60) {
        tphut = 0;
        tgio += 1;
    }
    cout << "Thoi gian con lai den nua dem: " << tgio << " gio, " << tphut << " phut, " << tgiay << " giay";
}