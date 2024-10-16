### Nội dung: Phát thưởng cho cuộc thi tin học, BTC có n quà được đánh số thứ tự 1 đến n, phần quà thứ i có giá trị ai.  

### BTC yêu cầu học sinh chọn các phần quà theo quy tắc sau:

- Phần quà chọn sau phải có số thứ tự lớn hơn phần quà chọn trước đó.
- Phần quà chọn sau phải có giá trị lớn hơn phần quà chọn trước đó ít nhất k giá trị.

**Yêu cầu:** Hãy giúp các học sinh chọn theo quy tắc của BTC sao cho số lượng phần quà là nhiều nhất.

**Dữ liệu:** vào từ file GIFT.inp:
- Dòng đầu chứa 2 số nguyên dương n và k (n <= 10^4, k <= 10^3).
- n dòng tiếp, dòng thứ i ghi số nguyên dương ai (ai <= 10^6) là giá trị của phần kết quả thứ i.
**Kết quả**: ghi ra file GIFT.out một dòng duy nhất chứa số lượng quà max thỏa mãn quy tắc BTC.

**Ví dụ:**
	
	GIFT.inp:

```
5 2
4
5
6
4
8

```

    GIFT.out

```
3
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Đọc dữ liệu từ file
    freopen("GIFT.inp", "r", stdin);
    freopen("GIFT.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n); // Mảng để lưu giá trị của các phần quà
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n, 1);  // dp[i] là số phần quà tối đa có thể chọn kết thúc tại vị trí i
    int maxx = -1e9;  // Khởi tạo giá trị lớn nhất với giá trị âm rất lớn

    // Duyệt qua từng cặp giá trị quà
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // Kiểm tra nếu phần quà hiện tại thỏa mãn điều kiện
            if (a[i] >= a[j] + k) {
                // Cập nhật dp[i] với số lượng phần quà tối đa có thể chọn kết thúc tại i
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // Cập nhật số lượng phần quà lớn nhất
        maxx = max(maxx, dp[i]);
    }

    cout << maxx << endl;  // Xuất kết quả ra file
    return 0;
}

```

### Giải thích các khái niệm:

1. **Vectors**: Sử dụng `vector<int>` để lưu giá trị của các phần quà.
    
2. **Dynamic Programming Table (**`dp`**)**: Mảng `dp` nơi `dp[i]` giữ số lượng phần quà tối đa có thể chọn kết thúc tại vị trí `i`.
    
3. **Nested Loops**: Với mỗi phần quà tại vị trí `i`, kiểm tra tất cả các phần quà trước đó để xem liệu nó có thỏa mãn điều kiện (giá trị phần quà sau lớn hơn phần quà trước ít nhất `k`).
    
4. **Updating DP Array**: Nếu thỏa mãn điều kiện, cập nhật `dp[i]` với giá trị lớn nhất giữa giá trị hiện tại và `dp[j] + 1`, đại diện cho chuỗi dài nhất tìm thấy cho đến hiện tại kết thúc tại `i`.
    
5. **Result Calculation**: Giá trị lớn nhất trong mảng `dp` đại diện cho chuỗi dài nhất của các phần quà có thể chọn theo quy tắc:.
    

Hiểu nôm na là: với mỗi phần quà, kiểm tra tất cả các phần quà trước đó để xem có thể thêm phần quà hiện tại vào một chuỗi hợp lệ không. Theo dõi chuỗi hợp lệ dài nhất kết thúc tại mỗi phần quà sử dụng mảng `dp`.