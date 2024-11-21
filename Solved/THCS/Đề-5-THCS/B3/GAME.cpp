#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n, LLONG_MAX);  // Sử dụng LLOnG_MAX để đại diện cho giá trị lớn ban đầu
    dp[0] = 0;  // Chi phí để đến ô đầu tiên là 0

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
            }
        }
    }

    cout << dp[n - 1] << endl;  // Chi phí ít nhất để đến ô cuối cùng
    return 0;
}
