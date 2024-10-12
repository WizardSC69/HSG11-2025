#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    freopen("DOOR.inp", "r", stdin);
    freopen("DOOR.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        int d = 0;
        while (gcd(a, b + d) == 1)
        {
            ++d;
        }

        cout << d << endl;
    }

    return 0;
}
