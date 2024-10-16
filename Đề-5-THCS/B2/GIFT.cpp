#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("GIFT.inp", "r", stdin);
    freopen("GIFT.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n, 1);  // dp[i] là số phần quà tối đa có thể chọn kết thúc ở vị trí i
    int maxx = -1e9;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] >= a[j] + k) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxx = max(maxx, dp[i]);
    }

    cout << maxx << endl;
    return 0;
}
