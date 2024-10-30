#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int n, a, b, s;
int main()
{
    freopen("COST.inp","r",stdin);
    freopen("COST.out","w",stdout);
    cin >> n >> a >> b;
    for (int x, i=1; i<=n; i++)
    {
        cin >> x;
        if (x == 2) s += a + b;
        else s += min(a,b);
    }
    cout << s << endl;
    return 0;
}
