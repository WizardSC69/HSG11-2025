**Bài 3. Đếm cặp phần tử**

Cho dãy số tự nhiên gồm `n` phần tử `a1, a2, ..., an` và số tự nhiên `k`.

**Yêu cầu:** Đếm số cặp chỉ số `(i, j)` mà `i < j` và `ai + aj = k` trong dãy.

**Dữ liệu:** vào từ file `CAPPT.InP`:

- Dòng đầu tiên chứa hai số nguyên `n`, `k` (2 ≤ n ≤ 3 * 10^6, 1 ≤ k ≤ 10^6)
    
- Dòng thứ hai là dãy số `a1, a2, ..., an` có giá trị không vượt quá 10^6.
    

**kết quả:** ghi ra file `CAPPT.OUT` chứa số cặp `ai, aj` có tổng bằng `k`.

**Ví dụ 1:**

- `CAPPT.inp`:

```
5 1
1 5 4 1 2
```

- `CAPPT.out`:

```
0
```

**Ví dụ 2:**

- `CAPPT.inp`:

```
4 6
3 2 3 3
```

- `CAPPT.out`:

```
3
```

**Ràng buộc:**

- **Subtask1:** Có 80% số test 1 ≤ n ≤ 10^3
    
- **Subtask2:** Có 20% số test còn lại 10^3 ≤ n ≤ 3 * 10^6

## Mã nguồn mẫu:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("CAPPT.InP", "r", stdin);
    freopen("CAPPT.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> c;
    int d = 0;

    for (int i = 0; i < n; ++i) {
        if (c.find(k - a[i]) != c.end()) {
            d += c[k - a[i]];
        }
        c[a[i]]++;
    }

    cout << d << endl;
    return 0;
}
```

### Giải thích

**Đếm số cặp có tổng bằng** `k`:

- `unordered_map<int, int> c;`: Sử dụng một bảng băm `c` để lưu số lượng xuất hiện của các phần tử trong dãy.
    
- `for (int i = 0; i < n; ++i)`: Duyệt qua các phần tử của dãy.
    
    - `if (c.find(k - a[i]) != c.end()) { d += c[k - a[i]]; }`: kiểm tra nếu `k - a[i]` đã xuất hiện trong bảng băm thì tăng biến `d` lên số lượng xuất hiện của `k - a[i]`.
        
    - `c[a[i]]++;`: Tăng số lượng xuất hiện của `a[i]` trong bảng băm.