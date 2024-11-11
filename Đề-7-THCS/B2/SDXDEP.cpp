#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra số đối xứng
bool dxung(int a) {
    string s = to_string(a);
    return s == string(s.rbegin(), s.rend());
}

// Hàm tìm các ước số nguyên tố
int sntd(int x) {
    int d = 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            ++d;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) ++d;
    return d;
}

int main() {
    freopen("SDXDEP.inp", "r", stdin);
    freopen("SDXDEP.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    int d = 0;
    for (int i = a; i <= b; ++i) {
        if (dxung(i) && sntd(i) >= 3) {
            ++d;
        }
    }

    cout << d << endl;
    return 0;
}

