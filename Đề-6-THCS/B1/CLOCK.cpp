#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("CLOCK.inp", "r", stdin);
  freopen("CLOCK.out", "w", stdout);

  int m, n;
  cin >> m >> n;

  cout << (m + n) % 60 << endl;

  return 0;
}
