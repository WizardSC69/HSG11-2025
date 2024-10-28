#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int c[N+2], cnt[N+2];
int n, k;

int main() {
    freopen("ZFACTOR.inp", "r", stdin);
    freopen("ZFACTOR.out", "w", stdout);
    
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}
    for (int i = 2; i <= k; i++) {
        if (c[i] == 0) {
            for (int j = i; j <= k; j += i) {
                if (c[j] == 0) c[j] = i;
            }
        }
    }

    for (int i = 2; i <= k; i++) {
        cnt[c[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[a[i]] << endl;
    }

    return 0;
}
