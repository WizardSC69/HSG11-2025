#include <bits/stdc++.h>
#define N 100000
using namespace std;

int a[N+2];
int n, m, ans;

int main() {
    freopen("PRIZE.INP", "r", stdin);
    freopen("PRIZE.OUT", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
	    cin >> a[i];
    }
    sort(a+1, a+m+1, greater<int>());
    
    for (int i = 1; i <= n; i++) {
        ans = max(ans, i * a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}

