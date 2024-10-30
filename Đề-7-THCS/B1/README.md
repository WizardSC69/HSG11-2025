Xác định độ "đẹp" của một số tự nhiên `n` dựa trên số lượng ước tự nhiên của nó. Nhiệm vụ là tính toán số lượng ước tự nhiên của `n`.

**Dữ liệu:** Vào từ file `SODEP.inp`, chứa duy nhất một số tự nhiên `n` (`1 ≤ n ≤ 10^14`).

**Kết quả:** Ghi ra file `SODEP.out` một số duy nhất là số lượng ước tự nhiên của `n`.

**Ví dụ 1:**

- `SODEP.inp`:

```
4
```

- `SODEP.out`:

```
3
```

**Ví dụ 2:**

- `SODEP.inp`:

```
1234
```

- `SODEP.out`: 

```
4 
```

### Mã nguồn mẫu:

```cpp
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
```

- **Tính số lượng ước**:
    
    - `for (ll i = 1; i * i <= n; ++i)`: Lặp từ 1 đến căn bậc hai của `N`.
        
    - `if (n % i == 0)`: Kiểm tra nếu `i` là ước của `n`.
        
    - `d += (i * i == n) ? 1 : 2;`: Nếu `i` là căn bậc hai của `n` thì tăng biến đếm `d` lên 1, ngược lại tăng lên 2 (vì `i` và `n/i` đều là ước của `n`).