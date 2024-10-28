**Bài toán: Phần thưởng**

Công ty Alpha tặng thưởng cho `n` công nhân có điểm số cao nhất từ tổng số `m` công nhân. Mỗi người có điểm số `p_i`. Mục tiêu là tìm tổng giá trị phần thưởng lớn nhất mà công ty có thể trao, với mỗi phần thưởng bằng điểm số của người có điểm số thấp nhất trong số những người được tặng thưởng.

**Dữ liệu:**

- **Input** từ file `PRIZE.INP` gồm:
    
    - Dòng đầu: Hai số nguyên `m` và `n` (`m, n ≤ 10^5`)
        
    - Dòng thứ hai: `m` số nguyên `p_1, p_2, ..., p_m` (`p_i ≤ 1000`)
        
- **Output:** Ghi ra file `PRIZE.OUT` một số nguyên duy nhất là kết quả bài toán.
**Ví dụ:**

- PRIZE.inp:

```
6 4
2 12 9 8 10 7
```

- PRIZE.out:

```
32
```

**Ví dụ 2:**

- PRIZE.inp:

```
4 5
9 3 1 6
```

-  PRIZE.out:

```
12
```

**Hạn chế:**

- **Subtask 1:** 60% test với `1 ≤ m, n ≤ 10^3`
    
- **Subtask 2:** 40% test với `10^3 < m, n ≤ 10^5`
### Mã nguồn mẫu:

```cpp
#include <bits/stdc++.h>
#define N 100000
using namespace std;

int a[N+2];
int n, m, ans;

int main() {
    freopen("PRIZE.INP", "r", stdin);
    freopen("PRIZE.OUT", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
	    cin >> a[i];
    }
    sort(a+1, a+m+1, greater<int>());
    
    for (int i = 1; i <= n; i++) {
        ans = max(ans, i * a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}

```
### Giải thích:

#### 1. Sắp xếp mảng `a` theo thứ tự giảm dần:

```cpp
    sort(a+1, a+m+1, greater<int>());
```

- Sắp xếp mảng `a` từ `a[1]` đến `a[m]` theo thứ tự giảm dần, tức là `a[1]` sẽ có điểm số lớn nhất.

#### 2. Tìm giá trị lớn nhất của tổng điểm số tối thiểu:

```cpp
    for (int i = 1; i <= n; i++) {
        ans = max(ans, i * a[i]);
    }
```

- Duyệt qua `n` phần tử đầu tiên của mảng `a`.
    
- Tính `i * a[i]` cho mỗi phần tử và cập nhật giá trị lớn nhất vào `ans`.
