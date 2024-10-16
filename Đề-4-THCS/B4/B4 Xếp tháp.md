**Nội dung:** Hội thi Olympic Khoa học viễn tưởng là một hội thi thường niên giữa các trường trung học cơ sở trên cả nước, trong đó có một trò chơi vận động là xếp tháp. Mỗi đội sẽ nhận được một số khối hộp và phải xếp chúng thành các tòa tháp theo quy tắc sau:

- Các khối hộp phải được xếp vào các tòa tháp đã có hoặc tạo tòa tháp mới.
- Khối hộp ở trên phải có thể tích không lớn hơn khối hộp ở dưới.
- Không được chuyển khối hộp từ tòa tháp này sang tòa tháp khác.
- Phải xếp được càng ít tòa tháp càng tốt.
    

**Yêu cầu:** Viết chương trình giúp đội xếp được số tòa tháp ít nhất.
**Dữ liệu:** Đọc từ file `TOWER.INP`:

- Dòng đầu tiên chứa số nguyên dương n là số lượng khối hộp.
- Dòng thứ hai chứa n số nguyên dương a₁, a₂, ..., aₙ (aᵢ ≤ 10⁹) là thể tích của các khối hộp.
    
**Kết quả:** Ghi ra file `TOWER.OUT` một dòng duy nhất là số lượng tòa tháp ít nhất có thể tạo thành.

**Ví dụ:**

- Input (`TOWER.INP`):

```
5
3 8 5 2 2	
```
- Output (`TOWER.OUT`):

```
2
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("TOWER.inp", "r", stdin);
    freopen("TOWER.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multiset<int> thap;

    for (int i = 0; i < n; ++i) {
        auto it = thap.upper_bound(a[i]);
        if (it != thap.end()) {
            thap.erase(it);
        }
        thap.insert(a[i]);
    }
    cout << thap.size() << endl;

    return 0;
}

```

1. **Tìm kiếm** `upper_bound`:

    ```
    auto it = thap.upper_bound(a[i]);
    ```
    
    - `thap.upper_bound(a[i])` tìm kiếm phần tử đầu tiên trong `multiset` `thap` có giá trị lớn hơn `a[i]`.
        
    - `it` là iterator trỏ đến vị trí của phần tử này.


1. **Kiểm tra và xóa phần tử**:

    ```
    if (it != thap.end()) {
        thap.erase(it);
    }
    ```
    
    - Nếu tìm thấy phần tử lớn hơn `a[i]` (tức là `it` không trỏ đến cuối `multiset`), thì xóa phần tử này khỏi `multiset`.
        
    - Việc xóa này tượng trưng cho việc đặt khối hộp 
     `a[i]` lên tòa tháp hiện tại và xóa tòa tháp cũ.
        
3. **Chèn phần tử mới vào** `multiset`:

    ```
    thap.insert(a[i]);
    ```
    
    - Chèn khối hộp `a[i]` vào `multiset`, nghĩa là cập nhật tòa tháp mới với khối hộp `a[i]` ở trên cùng.
        
4. **In số lượng tòa tháp**:

    ```
    cout << thap.size() << endl;
    ```

 - Sau khi duyệt qua tất cả các khối hộp, 
   số lượng phần tử trong `multiset` chính là số lượng tòa tháp cần thiết. Do đó, `thap.size()` sẽ cho biết số lượng tòa tháp tối thiểu có thể tạo ra.
        

### Tóm tắt:

- Mỗi lần thêm khối hộp vào tòa tháp, kiểm tra xem có thể đặt khối hộp này lên tòa tháp 
  hiện tại không.
    
- Nếu có, ta xóa tòa tháp cũ và cập nhật tòa tháp mới.
    
- Nếu không, tạo tòa tháp mới với khối hộp này.
    
- Kết quả cuối cùng là số lượng tòa tháp tối thiểu.