**Mô tả**:

- Cần tìm số vòng xoay ít nhất của núm thứ hai để mở cửa khi số của núm thứ nhất `a` là cố định.
    
- Số của núm thứ hai `b` cần được xoay thêm một số nguyên dương `x` để trở thành bội của một ước của `a`.
    

**Đầu vào**:

- Dòng thứ nhất chứa số nguyên dương `n` là số cặp giá trị `a` và `b` (1 ≤ n ≤ 100).
    
- `n` dòng tiếp theo, mỗi dòng chứa hai số nguyên `a` và `b` cách nhau bởi một dấu cách (2 ≤ a, b ≤ 10^9).
    

**Đầu ra**:

- Ghi ra file văn bản **[DOOR.OUT](https://DOOR.OUT)**, mỗi dòng một số nguyên là kết quả tìm được cho từng cặp `a` và `b`.

**Ví dụ:**

- Input:

 ```
3
15 7
23 11
35 42
 ```

- Output:

```
2
12
0
```

### Mã nguồn mẫu:

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main() {
    freopen("DOOR.inp", "r", stdin);
    freopen("DOOR.out", "w", stdout);
    cin >> n;

    for (int t = 1; t <= n; t++) {
        int a, b;
        cin >> a >> b;
        int ans = (a - b % a) % a;

        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                ans = min(ans, (i - b % i) % i);
                int k = a / i;
                ans = min(ans, (k - b % k) % k);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

```

#### 1. Vòng lặp chính để xử lý từng bộ dữ liệu:

```cpp
  for (int t = 1; t <= n; t++) {
    int a, b;
    cin >> a >> b;
    int ans = (a - b % a) % a;
```

- `for (int t = 1; t <= n; t++)`: Vòng lặp để xử lý từng bộ dữ liệu.
    
- `cin >> a >> b;`: Đọc hai số `a` và `b` từ file đầu vào.
    
- `int ans = (a - b % a) % a;`: Khởi tạo giá trị `ans` là số lần xoay cần thiết để `b` trở thành bội của `a`.

#### 2. Duyệt qua các ước của `a`:

```cpp
   for (int i = 2; i * i <= a; i++) {
		i​​f (a % i == 0) {
            ans = min(ans, (i - b % i) % i);
            int k = a / i;
            ans = min(ans, (k - b % k) % k);
        }
    }
        
    cout << ans << endl;
}
    return 0;
}
```

- `for (int i = 2; i * i <= a; i++)`: Duyệt qua các ước của `a` từ 2 đến sqrt(a).
    
- `if (a % i == 0)`: Kiểm tra nếu `i` là ước của `a`.
    
    - `ans = min(ans, (i - b % i) % i)`: Tính số lần xoay cần thiết với ước `i`.
        
    - `int k = a / i;`: Tìm ước khác của `a`.
        
    - `ans = min(ans, (k - b % k) % k)`: Tính số lần xoay cần thiết với ước `k`.

- Bước `(k - b % k) % k` giúp xử lý trường hợp đặc biệt khi `b % k` bằng 0. Điều này đảm bảo rằng kết quả cuối cùng luôn nằm trong phạm vi từ 0 đến k-1. Dưới đây là một ví dụ cụ thể:

### Ví dụ 1:

Giả sử `k = 5` và `b = 10`:

- **Bước 1**: `b % k = 10 % 5 = 0` (bởi vì 10 chia hết cho 5).
    
- **Bước 2**: `k - b % k = 5 - 0 = 5`.
    
- **Bước 3**: `(k - b % k) % k = 5 % 5 = 0`.
    

Kết quả là `0`, nghĩa là chúng ta không cần thêm bất kỳ số nào vào `10` để nó trở thành bội của `5`.

### Ví dụ 2:

Giả sử `k = 5` và `b = 8`:

- **Bước 1**: `b % k = 8 % 5 = 3`.
    
- **Bước 2**: `k - b % k = 5 - 3 = 2`.
    
- **Bước 3**: `(k - b % k) % k = 2 % 5 = 2`.
    

Kết quả là `2`, nghĩa là chúng ta cần thêm `2` vào `8` để nó trở thành bội của `5`.

### Tổng kết kiến thức cần dùng:

1. **Ước chung lớn nhất (GCD)**: Hiểu cách tính GCD và các tính chất liên quan.
    
2. **Thuyết đồng dư**: Hiểu về các phép toán đồng dư, đặc biệt là cách sử dụng các công thức đồng dư để tìm x sao cho `(a + x) % b == 0`.
    
3. **Tối ưu hóa vòng lặp**: Hiểu cách duyệt qua các ước của một số để giảm độ phức tạp tính toán.
 
4. **Xử lý I/O trong C++**: Sử dụng `freopen` để đọc và ghi dữ liệu từ file.