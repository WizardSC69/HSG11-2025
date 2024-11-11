**Bài 5. Đoạn con**

Cho dãy số nguyên gồm `N` phần tử `a1, a2, ..., an`. Một đoạn con là một dãy các phần tử liên tiếp bất kỳ trong dãy ban đầu. Hai đoạn con là khác nhau nếu tồn tại ít nhất một phần tử không thuộc cả hai đoạn.

Yêu cầu: Đếm số đoạn con mà tổng các lũy thừa bậc `M` của các phần tử trong đoạn đó chia hết cho `K`.

**Dữ liệu:** vào từ file `DOANCON.INP` gồm hai dòng:

- Dòng đầu chứa ba số nguyên dương `N, M, K` (`1 ≤ N ≤ 10^5`, `1 ≤ M ≤ 10^18`, `K ≤ 10^5`)
    
- Dòng thứ hai chứa `N` số tự nhiên `a1, a2, ..., an` (`1 ≤ ai ≤ 10^5`).
    

**Kết quả:** ghi ra file `DOANCON.OUT` số đoạn con mà có tổng các lũy thừa bậc `M` của các phần tử chia hết cho `K`.

**Ví dụ:**


- `DOANCON.inp`:

```
4 1 3
1 2 3 1
```

- `DOANCON.out`:

```
4
```

Trong ví dụ này, có bốn đoạn con có tổng chia hết cho `K` là 3: {3}, {2, 1}, {3, 2, 1}, và {1, 2}.

## Giải thích code

```cpp
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
```

### Giải thích chi tiết

## Biến toàn cục

```cpp
map<int, int> Mp;
int n, k;
ll m, ans;
```

- `Mp`: Một map để đếm số dư.
    
- `n`, `k`: Các số nguyên đại diện cho số phần tử và số chia.
    
- `m`: Một unsigned long long để biểu thị mũ mà cơ số được nâng lên.
    
- `ans`: Lưu trữ kết quả cuối cùng.

## Toán tử `%` cho Chuỗi

```cpp
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
```

- Hàm này tính số dư khi giá trị số của chuỗi `s` được chia cho `k`.
    

## Hàm Tính `a^m % k` Sử Dụng Chia Để Trị

```cpp
ll du(ll a, ll m, int k)
{
    if (m == 1) return (a % k);
    ll r = du(a, m/2, k);
    r = (r * r) % k;
    if (m % 2 == 1) r = (r * a) % k;
    return r;
}
```

- Hàm này tính đệ quy `a^m % k` sử dụng phương pháp lũy thừa nhị phân.
    

## Hàm chính

```cpp
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
```

- `freopen("DOANCON.inp", "r", stdin);` và `freopen("DOANCON.out", "w", stdout);` chuyển hướng luồng đầu vào và đầu ra từ/tới các tệp.
    
- `cin >> n >> m >> k;`: Đọc giá trị của `n`, `m`, và `k` từ tệp đầu vào.
    
- Khởi tạo `tong` với `0` và đặt `Mp[0]` là `1`.
    
- Với mỗi chuỗi `s` được đọc từ đầu vào, nó:
    
    - Tính số dư khi `s` được chia cho `k`.
        
    - Nâng `a` lên mũ `m` chia dư `k` bằng hàm `du`.
        
    - Thêm `a` vào tổng đang chạy `tong`.
        
    - Tăng `ans` bởi số lần xuất hiện của `tong % k` trong `Mp`.
        
    - Tăng số lượng của `tong % k` trong `Mp`.
        
- Xuất kết quả cuối cùng `ans`.

## Kiến thức:

- **Thư Viện STL (Standard Template Library)**: Sử dụng các cấu trúc dữ liệu trong STL như `map`, `vector`, và `string`.
    
- **Hàm và Đệ Quy**: Biết cách định nghĩa và sử dụng hàm, bao gồm hàm đệ quy.

- **Lũy Thừa và Chia Để Trị**: Biết cách tính lũy thừa một cách hiệu quả sử dụng phương pháp lũy thừa nhị phân (exponentiation by squaring).