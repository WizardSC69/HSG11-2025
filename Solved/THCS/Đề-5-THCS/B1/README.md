## Bài 1: Tìm UCLN lớn nhất của các cặp số trong mảng

### Mã nguồn mẫu (chưa tối ưu):

```cpp
#include <bít/stdc++.h:>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    freopen("CDIV.inp", "r", stdin);
    freopen("CDIV.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxGCD = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            maxGCD = max(maxGCD, gcd(a[i], a[j]));
        }
    }

    cout << maxGCD << endl;
    return 0;
}

```

### Mã nguồn mẫu (tối ưu):

```cpp
#include <bits/stdc++.h>
using namespace std;

#define N 1000000
int cnt[N+2];

int main() {
    freopen("CDIV.inp", "r", stdin);
    freopen("CDIV.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxa = -1e9;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        maxa = max(maxa, a[i]);
    }

    for (int i = 1; i <= maxa; ++i) {
        for (int j = 2 * i; j <= maxa; j += i) {
            cnt[i] += cnt[j];
        }
    }

    for (int i = maxa; i > 0; --i) {
        if (cnt[i] > 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}

```

**Giải thích:**
1. **Khai báo và định nghĩa**:
    
    - `#define N 1000000`: Định nghĩa hằng số N bằng 1 triệu.
        
    - `int cnt[N+2];`: Khai báo mảng `cnt` để đếm số lượng các giá trị và bội số của chúng. Mảng này có kích thước `N+2` để đảm bảo chứa đủ tất cả các giá trị cần thiết.
        
2. **Hàm** `main`:
    
    - `freopen("CDIV.inp", "r", stdin);` và `freopen("CDIV.out", "w", stdout);`: Mở file `CDIV.inp` để đọc dữ liệu và `CDIV.out` để ghi kết quả.
        
    - `cin >> n;`: Đọc số lượng phần tử `n`.
        
    - `vector<int> a(n);`: Khởi tạo mảng `a` để lưu các phần tử.
        
    - `int maxa = -1e9;`: Khởi tạo biến `maxa` để lưu giá trị lớn nhất trong mảng `a`.
        
3. **Đọc dữ liệu và cập nhật mảng** `cnt`:
    
    - `for (int i = 0; i < n; ++i) { ... }`: Duyệt qua tất cả các phần tử trong mảng `a`:
        
        - `cin >> a[i];`: Đọc giá trị phần tử vào mảng `a`.
            
        - `cnt[a[i]]++;`: Tăng biến đếm `cnt` của giá trị phần tử đó lên 1.
            
        - `maxa = max(maxa, a[i]);`: Cập nhật giá trị lớn nhất `maxa` trong mảng.
            
4. **Đếm số lượng bội số của mỗi giá trị**:
    
    - `for (int i = 1; i <= maxa; ++i) { for (int j = 2 * i; j <= maxa; j += i) { ... } }`: Duyệt qua tất cả các giá trị từ 1 đến `maxa`:
        
        - `for (int j = 2 * i; j <= maxa; j += i) { ... }`: Duyệt qua tất cả các bội số của `i` từ `2 * i` đến `maxa`:
            
            - `cnt[i] += cnt[j];`: Tăng biến đếm `cnt[i]` với số lượng các bội số của `i`.
                
5. **Tìm giá trị lớn nhất có số lần xuất hiện lớn hơn 1**:
    
    - `for (int i = maxa; i > 0; --i) { ... }`: Duyệt ngược từ `maxa` về 1:
        
        - `if (cnt[i] > 1) { cout << i << endl; break; }`: Nếu số lần xuất hiện của `i` lớn hơn 1, in giá trị `i` ra và kết thúc chương trình.
            

### Tóm tắt:

Code này giúp tìm ra giá trị lớn nhất trong mảng `a` sao cho nó có ít nhất hai bội số trong mảng. Bằng cách đếm số lượng các giá trị và bội số của chúng.