#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Hàm tính tổng các chữ số của một số
int sum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    freopen("BPAIRS.inp", "r", stdin);
    freopen("BPAIRS.out", "w", stdout);

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sử dụng unordered_map để lưu số lượng các số cùng tổng các chữ số
    unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i) {
        int s = sum(a[i]);
        umap[s]++;
    }

    // Đếm số lượng cặp số đẹp
    ll pairs = 0;
    for (const auto& pair : umap) {
        int d = pair.second;
        if (d > 1) {
            pairs += static_cast<ll>(d) * (d - 1) / 2;
        }
    }

    cout << pairs << endl;

    return 0;
}

