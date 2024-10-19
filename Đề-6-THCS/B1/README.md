Cần xác định vị trí của kim phút trên mặt đồng hồ sau một khoảng thời gian nhất định. Mặt đồng hồ được chia thành 60 vạch, đánh số từ 0 đến 59. Hiện tại, kim phút chỉ vào vạch có chỉ số là **m** (0 ≤ m < 60). Sau **n** phút, kim phút sẽ chỉ vào vạch số bao nhiêu?

### Dữ liệu:

- Đọc từ tệp `CLOCK.INP` gồm hai số nguyên dương `m` và `n` (n ≤ 10^18).
    

### Kết quả:

- Ghi ra tệp `CLOCK.OUT` một dòng chứa một số nguyên là kết quả bài toán.
    

### Thuật toán đề xuất:

- Hiện tại, đồng hồ chỉ **m** phút, vậy sau **n** phút kim phút sẽ chỉ vào vị trí là `(m + n) % 60`.
    

### Độ phức tạp:

- O(1)
    

### Ví dụ:

`CLOCK.INP`:

```
5 19
```

`CLOCK.OUT`:

```
24
```

### Mã nguồn mẫu:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {

	freopen("CLOCK.inp", "r", stdin);
	freopen("CLOCK.out", "w", stdout);

	int m, n; cin >> m >> n;

	cout<< (m + n) % 60 << endl;
	
	return 0;
}
```

