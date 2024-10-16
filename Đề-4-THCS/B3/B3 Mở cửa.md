**Nội dung:** Có hai núm xoay hình tròn trên ổ khóa của cánh cửa, núm thứ nhất chỉ số `a` và núm thứ hai chỉ số `b`. Cửa sẽ mở khi `a` và `b` có ước chung lớn hơn 1. Tuy nhiên, núm thứ nhất bị kẹt và không thể xoay, chỉ có thể xoay núm thứ hai.
**Yêu cầu:** Xác định số vòng xoay tối thiểu cần thực hiện trên núm thứ hai để mở cửa.

**Dữ liệu:**

- Đọc từ file `DOOR.inp`:

    - Dòng đầu tiên chứa số nguyên `n` là số cặp `a, b` (1 ≤ n ≤ 100)
    - Dòng thứ `i` trong `n` dòng tiếp theo chứa hai số nguyên `a` và `b` cách nhau một dấu cách (2 ≤ a, b ≤ 10^9)

**Kết quả:**

- Ghi ra file `DOOR.out` với mỗi test là một dòng chứa số vòng xoay tối thiểu để mở cửa.
    
**Ví dụ:** `DOOR.inp`:

```
3
15 7
23 11
35 42
```

**Ví dụ:** `DOOR.out`:

```
2
12
0
```

**Giới hạn:**

- `Subtask1`: 50% số test tương ứng với n = 1, 1 <= a,b <= 10^5.
- `Subtask2`: 30% số test tiếp theo tương ứng với n = 1, 1 <= a,b <= 10^5.
- `Subtask3`: 20% số test còn lại không ràng buộc.


```cpp
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {

	while (b != 0) {

		int t = b;
		b = a % b;
		a = t;
	}

	return a;
}

  

int main() {

	freopen("DOOR.inp", "r", stdin);
	freopen("DOOR.out", "w", stdout);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
	int a, b, d = 0; cin >> a >> b;
	
	while (gcd(a, b + d) == 1) {
			++d;
		}
		cout << d << endl;
	}
	
	return 0;
}
```

### Giải thích chi tiết:

1. **Khởi tạo biến** `d`:

    ```
    int d = 0;
    ```
    
    - `d` được khởi tạo với giá trị 0. Biến này đại diện cho số vòng xoay cần thực hiện trên núm thứ hai `b`.
        
2. **Kiểm tra điều kiện** `while`:

    ```
    while (gcd(a, b + d) == 1) {
    ```
    
    - Vòng lặp `d` sẽ tiếp tục chạy miễn là `gcd(a, b + d)` bằng 1.
        
    - `gcd(a, b + d)` sử dụng hàm `gcd` để tính ước chung lớn nhất của `a` và `b + d`.
        
    - Nếu GCD bằng 1, nghĩa là `d` và `b + d` không có ước chung nào lớn hơn 1, và chúng ta cần tiếp tục xoay núm thứ hai `b`.
        
3. **Tăng giá trị** `d`:

    ```
    ++d;
    ```
    
    - Mỗi lần vòng lặp chạy, giá trị của `count` sẽ được tăng lên 1.
    - Điều này tương đương với việc xoay núm thứ hai thêm một lần. 
### Tóm tắt:

- Vòng lặp `while` kiểm tra nếu `a` và `b + d` không có ước chung lớn hơn 1 (bằng cách tính GCD).
    
- Nếu GCD bằng 1, vòng lặp tiếp tục và `d` tăng lên, tức là xoay núm `b` thêm một lần.
    
- Vòng lặp chỉ dừng lại khi GCD của `a` và `b + d` lớn hơn 1, nghĩa là núm `b` đã đạt đến vị trí mà nó cùng chia sẻ một ước chung lớn hơn 1 với `a`, và cửa có thể mở.

