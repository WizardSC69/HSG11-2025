#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    freopen("SODEP.inp", "r", stdin);
    freopen("SODEP.out", "w", stdout);
    
    ll n;
    cin >> n;
    
    int d = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            d += (i * i == n) ? 1 : 2;
        }
    }
    
    cout << d << endl;
    return 0;
}
