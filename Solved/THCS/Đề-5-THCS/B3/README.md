Nhân dịp kỷ niệm ngày thành lập Đoàn, cô Tổng phụ trách tổ chức một trò chơi cho các bạn lớp 9 như sau: Có **N** ô vuông được vẽ thẳng hàng trên sân trường, các ô vuông được đánh số thứ tự từ 1 đến N. Mỗi ô vuông i có giá trị năng lượng là **h_i**. Một bạn học sinh đang ở ô thứ i, bạn ấy có thể nhảy tới ô vuông tiếp theo theo các cách:

- Nếu đang ở ô thứ i bạn có thể nhảy đến ô vuông thứ tự i + 1, i + 2, ..., i + k.
    
- Chi phí năng lượng tiêu hao cho một lần nhảy là |h_i - h_j| với h_j là ô đích mà bạn nhảy tới.
    

Bạn học sinh nào di chuyển từ ô 1 đến ô N với chi phí năng lượng thấp nhất sẽ được cô thưởng một phần quà.

### Yêu cầu:

Hãy tìm chi phí thấp nhất để giúp các học sinh nhảy từ ô vuông số 1 đến ô vuông thứ N.

### Dữ liệu:

Đọc từ file `GAME.INP`:

- Dòng đầu tiên chứa hai số nguyên dương N và k, trong đó N (2 ≤ N ≤ 10^5) là số ô vuông và k (1 ≤ k ≤ 100) là số ô vuông tối đa mà bạn học sinh có thể nhảy qua.
    
- Dòng thứ hai chứa N giá trị h_i (1 ≤ h_i ≤ 10^4), mỗi số cách nhau một ký tự trắng là chi phí năng lượng của ô thứ i.
    

### Kết quả:

Ghi ra file `GAME.OUT` một số nguyên là chi phí năng lượng ít nhất.

### Ví dụ:

`GAME.INP`:
```
5 3
10 25 35 40 20
```

`GAME.OUT`:
```
20
```

### Giải thích:

Cách nhảy của bạn học sinh sẽ là: 1 → 2 → 5, tổng chi phí năng lượng sẽ là |25 - 10| + |20 - 25| = 20.

### Mã nguồn mẫu:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n, LLONG_MAX);  // Sử dụng LLONG_MAX để đại diện cho giá trị lớn ban đầu
    dp[0] = 0;  // Chi phí để đến ô đầu tiên là 0

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
            }
        }
    }

    cout << dp[n - 1] << endl;  // Chi phí ít nhất để đến ô cuối cùng
    return 0;
}
```

### Giải thích:

```cpp
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
            }
        }
    }
```

- **Vòng lặp chính**: Duyệt qua từng ô từ `i = 0` đến `n-1`.
    
    - **Vòng lặp phụ**: Duyệt qua các bước nhảy từ `1` đến `k`.
        
        - **Điều kiện**: Kiểm tra nếu ô tiếp theo `i + j` nằm trong phạm vi mảng `a`.
            
        - **Cập nhật** `dp`: Cập nhật chi phí để đến ô `i + j` bằng cách lấy giá trị nhỏ nhất giữa giá trị hiện tại của `dp[i + j]` và chi phí để đến ô `i` cộng với độ chênh lệch độ cao giữa ô `i` và ô `i + j`.

### Tổng hợp kiến thức:

1. **Quy hoạch động (Dynamic Programming)**:
    
    - Hiểu cách thiết lập và sử dụng mảng `dp` để lưu trữ chi phí năng lượng tối thiểu để đến từng ô vuông.
        
    - Khả năng cập nhật giá trị mảng `dp` dựa trên các trạng thái trước đó theo từng bước nhảy.
        
2. **Cấu trúc dữ liệu cơ bản**:
    
    - Sử dụng mảng (`vector`) để lưu trữ giá trị năng lượng của các ô vuông.
        
    - Sử dụng các phép tính cơ bản trên mảng (truy cập, cập nhật, duyệt qua mảng).
        
3. **Tối ưu hóa thuật toán**:
    
    - Hiểu các phép tính tối thiểu (`min`) và sử dụng các giá trị lớn nhất ban đầu (`LLONG_MAX`) để khởi tạo.
        
    - Khả năng tối ưu hóa thời gian tính toán bằng cách giới hạn phạm vi duyệt qua mảng.
        
4. **Cấu trúc điều khiển**:
    
    - Sử dụng các vòng lặp (`for`) lồng nhau để duyệt qua các chỉ số của mảng.
        
    - Sử dụng điều kiện (`if`) để đảm bảo các bước nhảy nằm trong phạm vi mảng.
        
5. **Xử lý tệp tin**:
    
    - Sử dụng `freopen` để đọc dữ liệu từ file đầu vào và ghi kết quả ra file đầu ra.
        
    - Hiểu cách làm việc với các dòng đầu vào và các định dạng của dữ liệu trong file.
        
6. **Tính toán toán học cơ bản**:
    
    - Khả năng tính toán độ chênh lệch độ cao giữa các ô vuông bằng phép toán giá trị tuyệt đối (`abs`).