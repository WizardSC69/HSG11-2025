#include <bits/stdc++.h>
using namespace std;

int main() {
    // Mở file để đọc dữ liệu đầu vào và ghi kết quả
    freopen("TAOXAU.inp", "r", stdin);
    freopen("TAOXAU.out", "w", stdout);

    string x;
    cin >> x;

    // Sử dụng deque để quản lý xâu y
    deque<char> y;
    bool rev = false;

    // Lặp qua từng ký tự trong xâu x
    for (char c : x) {
        if (rev) {
            y.push_front(c);
        } else {
            y.push_back(c);
        }
        rev = !rev;
    }

    // Chuyển deque thành chuỗi và in kết quả
    for (char c : y) {
        cout << c;
    }
    cout << endl;

    return 0;
}


