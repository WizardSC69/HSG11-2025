### Bài 4: Thừa số nguyên tố nhỏ nhất

#### Đề bài

- Cho một số nguyên dương `P (P ≥ 2)`, ta có thể phân tích `P` thành tích các thừa số nguyên tố, trong đó có một thừa số nguyên tố nhỏ nhất.
    
- **Ví dụ:**
    
    - `100 = 2 * 2 * 5 * 5` thì 2 là thừa số nguyên tố nhỏ nhất của 100;
        
    - `15 = 3 * 5` thì 3 là thừa số nguyên tố nhỏ nhất của 15;
        
    - `17 = 17` thì 17 là thừa số nguyên tố nhỏ nhất của 17.
        

**Yêu cầu:**

- Đếm xem trong đoạn `[2, k]` có bao nhiêu số nguyên có thừa số nguyên tố nhỏ nhất là `a_i (1 ≤ i ≤ n)`.
    

**Dữ liệu:**

- **Input** từ file `ZFACTOR.INP`:
    
    - Dòng đầu chứa hai số nguyên dương `n` và `k` (`1 ≤ n ≤ 10^5, 2 ≤ k ≤ 10^6`)
        
    - Dòng thứ 2 chứa `n` số nguyên tố `a_1, a_2, ..., a_n (2 ≤ a_i ≤ k, 1 ≤ i ≤ n)`.
        

**Kết quả:**

- Ghi ra file `ZFACTOR.OUT` gồm `n` dòng, với dòng thứ `i` là số lượng số nguyên trong đoạn `[2, k]` có thừa số nguyên tố nhỏ nhất là `a_i`.

### Mã nguồn mẫu:

```cpp
#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int c[N+2], cnt[N+2];
int n, k;

int main() {
    freopen("ZFACTOR.inp", "r", stdin);
    freopen("ZFACTOR.out", "w", stdout);
    
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}
    for (int i = 2; i <= k; i++) {
        if (c[i] == 0) {
            for (int j = i; j <= k; j += i) {
                if (c[j] == 0) c[j] = i;
            }
        }
    }

    for (int i = 2; i <= k; i++) {
        cnt[c[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[a[i]] << endl;
    }

    return 0;
}
```

### Giải thích:

**1. Khai báo và khởi tạo:**

```cpp
int c[N+2], cnt[N+2];
int n, k;
```

- `c[]`: mảng lưu thừa số nguyên tố nhỏ nhất của mỗi số trong đoạn `[2, k]`.

- `cnt[]`: mảng đếm số lượng số nguyên có thừa số nguyên tố nhỏ nhất là các số `a_i`.

**2. Sàng nguyên tố để tìm thừa số nguyên tố nhỏ nhất:**

```cpp
for (int i = 2; i <= k; i++) {
    if (c[i] == 0) {
        for (int j = i; j <= k; j += i) {
            if (c[j] == 0) c[j] = i;
        }
    }
}
```

**Mục tiêu:** Xác định thừa số nguyên tố nhỏ nhất của mỗi số trong đoạn `[2, k]`.

- **for (int i = 2; i <= k; i++)**:
    
    - Duyệt qua tất cả các số từ `2` đến `k`.
        
- **if (c[i] == 0)**:
    
    - Kiểm tra xem `i` có phải là số nguyên tố hay không. Nếu `c[i]` vẫn bằng `0`, nghĩa là `i` là một số nguyên tố vì nó chưa được đánh dấu bởi bất kỳ thừa số nguyên tố nào.
        
- **for (int j = i; j <= k; j += i)**:
    
    - Duyệt qua tất cả các bội số của `i` từ `i` đến `k`.
        
    - **if (c[j] == 0) c[j] = i**:
        
        - Nếu `j` chưa có thừa số nguyên tố nhỏ nhất (tức là `c[j] == 0`), gán `c[j]` bằng `i` vì `i` là thừa số nguyên tố nhỏ nhất của `j`.
**Kết quả:**

- Sau khi hoàn thành vòng lặp, mảng `c` sẽ lưu trữ thừa số nguyên tố nhỏ nhất của mỗi số trong đoạn `[2, k]`. Ví dụ, `c[10] = 2`, `c[15] = 3`, `c[17] = 17`.

**3. Đếm số lượng số nguyên có thừa số nguyên tố nhỏ nhất:**

```cpp
for (int i = 2; i <= k; i++) {
    cnt[c[i]]++;
}
```

**Mục tiêu:** Đếm số lượng các số nguyên trong đoạn `[2, k]` có thừa số nguyên tố nhỏ nhất là các số `a_i`.

- **for (int i = 2; i <= k; i++)**:
    
    - Duyệt qua tất cả các số từ `2` đến `k`.
        
- **cnt[c[i]]++**:
    
    - Tăng giá trị của `cnt[c[i]]` lên 1, nghĩa là tăng số lượng các số nguyên có thừa số nguyên tố nhỏ nhất là `c[i]`.
        

**Kết quả:**

- Mảng `cnt` sẽ lưu trữ số lượng các số nguyên có thừa số nguyên tố nhỏ nhất là các số `a_i`. Ví dụ, `cnt[2]` là số lượng các số nguyên trong đoạn `[2, k]` có thừa số nguyên tố nhỏ nhất là `2`.
