/*Viết chương trình nhập vào một số nguyên có tối đa 3 chữ số (ví dụ: từ 0 đến 999).
Chương trình sẽ đọc số đó thành chữ tiếng Việt, ví dụ:
135 → “một trăm ba mươi lăm”
507 → “năm trăm lẻ bảy”
20 → “hai mươi”
0 → “không”*/
#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    if (num < 0 || num > 999) {
        cout << "So khong hop le";
        return 0;
    }
    if (num == 0) {
        cout << "khong";
        return 0;
    }
    string ones[] = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    string teens[] = {"muoi", "muoi mot", "muoi hai", "muoi ba", "muoi bon", "muoi lam", "muoi sau", "muoi bay", "muoi tam", "muoi chin"};
    string tens[] = {"", "", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi"};
    
    int hundred = num / 100;
    int ten = (num / 10) % 10;
    int one = num % 10;

    if (hundred > 0) {
        cout << ones[hundred] << " tram ";
    }
    if (ten == 1) {
        cout << teens[one];
    } else if (ten > 1) {
        cout << tens[ten] << " ";
        if (one > 0) {
            cout << ones[one];
        }
    } else if (ten == 0 && one > 0 && hundred > 0) {
        cout << "le " << ones[one];
    } else if (ten == 0 && one > 0) {
        cout << ones[one];
    }
    return 0;
}
