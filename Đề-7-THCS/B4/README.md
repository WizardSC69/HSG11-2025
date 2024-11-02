**Bài 4. Tạoxâu**

Cho một xâu ký tự `x` gồm các chữ cái in thường từ `a` đến `z`. Độ dài xâu `x` không quá 10610^6. Người ta mã hóa xâu `x` thành xâu `y` như sau:

- Ban đầu xâu y rỗng.
    
- Đưa một ký tự từ xâu `x` vào cuối xâu `y` và liên tục đảo ngược `y`. Các ký tự của `x` lần lượt được đưa vào xâu `y` theo cách này.
    

**Yêu cầu:** Hãy in ra xâu `y` cuối cùng nhận được khi đã đưa hết ký tự xâu `x` vào.

**Dữ liệu:** Vào file `TAOXAU.inp` gồm một dòng duy nhất chứa xâu `x`.

**Kết quả:** Ghi ra file `TAOXAU.out` xâu `y` tìm được.

**Ví dụ:**

| TAOXAU.inp | TAOXAU.out | Giải thích                                                                                                                                                                                             |
| ---------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| abc        | cab        | Đưa lần lượt ký tự vào xâu `y` như sau:<br> Bước 1: đưa 'a' và đảo ngược `y` được `y` = "a"<br> Bước 2: đưa 'b' và đảo ngược `y` được `y` = "ba"<br> Bước 3: đưa 'c' và đảo ngược `y` được `y` = "cab" |

**Ràng buộc:**

- **Subtask 1:** Có 55% số test độ dài xâu `x` không quá 255
    
- **Subtask 2:** Có 20% số test độ dài xâu `x` không quá 10410^4
    
- **Subtask 3:** Có 25% số test độ dài xâu `x` không quá 10610^6
    

## Giải thích code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Mở file để đọc dữ liệu đầu vào và ghi kết quả
    freopen("TAOXAU.inp", "r", stdin);
    freopen("TAOXAU.out", "w", stdout);

    string x;
    cin >> x;

    // Sử dụng deque để quản lý xâu y
    deque<char> y;
    bool rev = false;

    // Lặp qua từng ký tự trong xâu x
    for (char c : x) {
        if (rev) {
           y.push_front(c);
        } else {
           y.push_back(c);
        }
        rev = !rev;
    }

    // Chuyển deque thành chuỗi và in kết quả
    for (char c : y) {
        cout << c;
    }
    cout << endl;

    return 0;
}
```

### Giải thích

**Quản lý xâu** `y` **bằng deque**:

- Khai báo `deque<char>y;` và `bool reverse_flag = false;` có độ phức tạp O(1).
    
- Vòng lặp `for (char c : x)` thực hiện `n` lần, mỗi lần:
    
    - `Y.push_front(c)` hoặc `Y.push_back(c)`: Cả hai thao tác này trên deque có độ phức tạp O(1).
        
    - `reverse_flag = !reverse_flag;`: Thao tác này có độ phức tạp O(1).

Deque đặc biệt hữu dụng cho bài này vì khả năng thêm và xóa phần tử từ cả hai đầu (đầu và cuối) một cách hiệu quả, với độ phức tạp O(1) cho mỗi thao tác. Đây là lý do tại sao deque là lựa chọn tốt:

## Deque là gì?

Deque, viết tắt của "Double-Ended Queue," là một cấu trúc dữ liệu cung cấp khả năng thêm và xóa phần tử từ cả hai đầu (đầu và cuối) một cách hiệu quả. Deque thuộc thư viện tiêu chuẩn C++ và được định nghĩa trong header `<deque>`.

### Tính năng chính của Deque

1. **Thêm/xóa phần tử ở cả hai đầu**: Khác với queue thông thường chỉ cho phép thêm ở cuối và xóa ở đầu, deque cho phép thao tác ở cả hai phía.
    
2. **Truy cập ngẫu nhiên**: Deque cho phép truy cập phần tử ngẫu nhiên giống như vector với độ phức tạp O(1).
    
3. **Hiệu quả**: Các thao tác thêm/xóa ở đầu hoặc cuối của deque có độ phức tạp trung bình O(1).
    

### Các phương thức chính

- `push_back(value)`: Thêm phần tử `value` vào cuối deque.
    
- `push_front(value)`: Thêm phần tử `value` vào đầu deque.
    
- `pop_back()`: Xóa phần tử ở cuối deque.
    
- `pop_front()`: Xóa phần tử ở đầu deque.
    
- `at(index)`: Truy cập phần tử tại vị trí `index`.
    
- `size()`: Trả về số lượng phần tử trong deque.

### Ví dụ

Dưới đây là một ví dụ cơ bản sử dụng deque:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Thêm phần tử vào cuối
    dq.push_back(10);
    dq.push_back(20);

    // Thêm phần tử vào đầu
    dq.push_front(5);

    // Truy cập và in các phần tử
    cout << "Phan tu dau tien: " << dq.front() << endl;
    cout << "Phan tu cuoi cung: " << dq.back() << endl;

    // Xóa phần tử ở đầu và cuối
    dq.pop_front();
    dq.pop_back();

    // In phần tử còn lại
    cout << "Phan tu con lai: " << dq.front() << endl;

    return 0;
}
```

### Ưu điểm của Deque

- **Linh hoạt**: Cung cấp các thao tác linh hoạt ở cả hai đầu, giúp giải quyết nhiều bài toán một cách hiệu quả.
    
- **Hiệu suất cao**: Tối ưu cho các thao tác thêm/xóa ở đầu và cuối với độ phức tạp O(1).
### Tại sao Deque lại hữu dụng?

1. **Thêm/xóa linh hoạt**: Trong bài toán này, khi chúng ta cần thêm ký tự vào cuối xâu `Y` và liên tục đảo ngược `Y`, việc dùng deque giúp ta linh hoạt chèn ký tự vào đầu hoặc cuối mà không cần đảo ngược toàn bộ xâu.
    
2. **Tối ưu hóa hiệu suất**: Thay vì phải đảo ngược xâu `Y` mỗi khi thêm ký tự, chúng ta chỉ cần thêm vào đầu hoặc cuối deque, giúp giảm đáng kể số lần thao tác tốn kém.
    
3. **Tiết kiệm thời gian**: Deque giúp tiết kiệm thời gian và tối ưu hóa quá trình xây dựng xâu `Y`, đặc biệt khi độ dài xâu `X` có thể lên đến 10610^6.
    
### Độ phức tạp của thuật toán

- **Thêm vào đầu/cuối Deque**: Mỗi thao tác thêm vào đầu hoặc cuối deque có độ phức tạp trung bình là O(1).
    
- **Duyệt qua xâu** `X`: Độ phức tạp cho việc duyệt qua xâu `X` là O(n), với `n` là độ dài của xâu `X`.
    
Tổng thể, độ phức tạp của thuật toán sử dụng deque cho bài toán này là O(n), với `n` là số lượng ký tự trong xâu `X`. Điều này rất hiệu quả và phù hợp cho các trường hợp khi `n` có giá trị lớn, giúp xử lý dữ liệu nhanh và hiệu quả hơn so với việc phải đảo ngược toàn bộ chuỗi mỗi lần.

