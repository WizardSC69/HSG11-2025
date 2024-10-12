#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("TOWER.inp", "r", stdin);
    freopen("TOWER.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multiset<int> thap;

    for (int i = 0; i < n; ++i) {
        auto it = thap.upper_bound(a[i]);
        if (it != thap.end()) {
            thap.erase(it);
        }
        thap.insert(a[i]);
    }
    cout << thap.size() << endl;

    return 0;
}
