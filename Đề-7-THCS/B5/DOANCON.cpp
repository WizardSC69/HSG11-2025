#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
map<int, int> Mp;
int n, k;
ll m, ans;

// Tìm số dư của s và k
int operator % (string s, int k)
{
    int r = 0;
    for (auto x: s)
    {
        r = r * 10 + (x - '0');
        r %= k;
    }
    return r;
}

// Dùng chia để trị để tính a^m % k
ll du(ll a, ll m, int k)
{
    if (m == 1) return (a % k);
    ll r = du(a, m/2, k);
    r = (r * r) % k;
    if (m % 2 == 1) r = (r * a) % k;
    return r;
}

int main()
{
    freopen("DOANCON.inp", "r", stdin);
    freopen("DOANCON.out", "w", stdout);
    cin >> n >> m >> k;
    ll tong = 0;
    Mp[0] = 1;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        ll a = s % k;
        a = du(a, m, k);
        tong += a;
        ans += Mp[tong % k];
        Mp[tong % k]++;
        }
    cout << ans;
    return 0;
}
