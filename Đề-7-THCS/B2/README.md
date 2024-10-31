**Bài 2. Số đối xứng đẹp**

Một số tự nhiên được gọi là số đối xứng nếu viết các chữ số của nó theo chiều ngược lại thì vẫn thu được chính nó. Ví dụ, các số 66, 121 là những số đối xứng.

Một số được coi là số đẹp nếu nó là số đối xứng và có từ 3 ước số nguyên tố khác nhau trở lên. Ví dụ: 282 là số đẹp vì nó đối xứng và có 3 ước nguyên tố khác nhau là 2, 3, 47; hoặc 585 cũng là số đẹp vì nó là số đối xứng và có 4 ước nguyên tố khác nhau là 5, 9, 13, 45.

**Yêu cầu:** Cho hai số nguyên dương `a`, `b`. Đưa ra số lượng số đẹp trong đoạn từ `a` đến `b`.

**Dữ liệu:** vào từ file `SDXDEP.INP` chứa hai số nguyên dương `a`, `b` (1 < a < b ≤ 10^7).

**Kết quả:** ghi ra file `SDXDEP.OUT` một số duy nhất là số lượng số đẹp từ `a` đến `b`.

**Ví dụ:**

- `SDXDEP.inp`:

```
1 1000
```

- `SDXDEP.out`:

```
25
```

Các số đẹp trong đoạn từ 1 đến 1000 là: 66, 222, 252, 282, 414, 434, 444, 474, 494, 525, 555, 585, 595, 606, 616, 636, 646, 666, 696, 777, 828, 858, 868, 888, 969

**Ràng buộc:**

- **Subtask1:** Có 80% số test 1 ≤ a < b ≤ 10^4
    
- **Subtask2:** Có 20% số test còn lại 10^5 ≤ a < b ≤ 10^7

## Giải thích code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra số đối xứng
bool dxung(int a) {
    string s = to_string(a);
    return s == string(s.rbegin(), s.rend());
}

// Hàm tìm các ước số nguyên tố
int sntd(int x) {
    int d = 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            ++d;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) ++d;
    return d;
}

int main() {
    freopen("test1.inp", "r", stdin);
    freopen("test1.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    int d = 0;
    for (int i = a; i <= b; ++i) {
        if (dxung(i) && sntd(i) >= 3) {
            ++d;
        }
    }

    cout << d << endl;
    return 0;
}

```

### Giải thích

### Hàm kiểm tra số đối xứng

```cpp
bool dxung(int a) {
    string s = to_string(a);
    return s == string(s.rbegin(), s.rend());
}
```

- `dxung(int a)`: Hàm này kiểm tra xem một số `a` có phải là số đối xứng hay không.
    
- `string s = to_string(a);`: Chuyển số nguyên `a` thành chuỗi `s`.
    
- `s == string(s.rbegin(), s.rend());`: So sánh chuỗi `s` với chuỗi ngược của nó. Nếu hai chuỗi bằng nhau, `a` là số đối xứng.
    

### Hàm tìm các ước số nguyên tố

```cpp
int sntd(int x) {
    int d = 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            ++d;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) ++d;
    return d;
}
```

- `sntd(int x)`: Hàm này đếm số lượng ước số nguyên tố khác nhau của `x`.
    
- `int d = 0;`: Biến `d` được sử dụng để đếm số lượng ước số nguyên tố.
    
- `for (int i = 2; i <= sqrt(x); ++i)`: Duyệt từ 2 đến căn bậc hai của `x` để tìm các ước.
    
- `if (x % i == 0)`: Kiểm tra nếu `i` là ước của `x`.
    
- `++d;`: Tăng biến đếm `d` khi tìm thấy một ước số nguyên tố mới.
    
- `while (x % i == 0) { x /= i; }`: Loại bỏ tất cả các bội số của `i` khỏi `x`.
    
- `if (x > 1) ++d;`: Nếu còn lại ước số nguyên tố lớn hơn căn bậc hai của `x`, tăng biến đếm `d`.
    

### Hàm chính

```cpp
int main() {
    freopen("test1.inp", "r", stdin);
    freopen("test1.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    int d = 0;
    for (int i = a; i <= b; ++i) {
        if (dxung(i) and sntd(i) >= 3) {
            ++d;
        }
    }

    cout << d << endl;
    return 0;
}
```

- `freopen("test1.inp", "r", stdin); freopen("test1.out", "w", stdout);`: Mở file `test1.inp` để đọc dữ liệu và `test1.out` để ghi kết quả.
    
- `int a, b;`: Khai báo hai biến `a` và `b`.
    
- `cin >> a >> b;`: Đọc giá trị của `a` và `b` từ file đầu vào.
    
- `int d = 0;`: Khởi tạo biến `d` để đếm số lượng số đẹp.
    
- `for (int i = a; i <= b; ++i)`: Duyệt qua tất cả các số từ `a` đến `b`.
    
    - `if (dxung(i) && sntd(i) >= 3)`: Kiểm tra nếu số `i` là số đối xứng và có ít nhất 3 ước số nguyên tố khác nhau.
        
        - `++d;`: Tăng biến đếm `d` nếu thỏa mãn điều kiện.
            
- `cout << d << endl;`: Ghi kết quả ra file đầu ra.
    
- `return 0;`: Kết thúc chương trình.
    

Đoạn code này giúp xác định số lượng các số đẹp trong khoảng từ `a` đến `b` bằng cách kiểm tra cả tính đối xứng và số lượng ước số nguyên tố của mỗi số. 