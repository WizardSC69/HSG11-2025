#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    freopen("CDIV.inp", "r", stdin);
    freopen("CDIV.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxGCD = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            maxGCD = max(maxGCD, gcd(a[i], a[j]));
        }
    }
    cout << maxGCD << endl;

    return 0;
}
