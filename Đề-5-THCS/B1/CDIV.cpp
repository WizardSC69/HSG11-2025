#include <bits/stdc++.h>
using namespace std;

#define N 1000000
int cnt[N+2];

int main() {
    freopen("CDIV.inp", "r", stdin);
    freopen("CDIV.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxa = -1e9;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        maxa = max(maxa, a[i]);
    }

    for (int i = 1; i <= maxa; ++i) {
        for (int j = 2 * i; j <= maxa; j += i) {
            cnt[i] += cnt[j];
        }
    }

    for (int i = maxa; i > 0; --i) {
        if (cnt[i] > 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
