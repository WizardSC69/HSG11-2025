#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("CAPPT.inp", "r", stdin);
    freopen("CAPPT.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> c;
    int d = 0;

    for (int i = 0; i < n; ++i) {
        if (c.find(k - a[i]) != c.end()) {
            d += c[k - a[i]];
        }
        c[a[i]]++;
    }

    cout << d << endl;
    return 0;
}

