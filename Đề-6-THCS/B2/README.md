Tý rất thích chơi bi nhưng chỉ thích những viên bi màu đỏ và màu xanh. Hôm nay, Tý cần mua bi bỏ vào n cái hộp, mỗi hộp chỉ chứa được một hoặc hai viên bi. Nếu hộp chứa hai viên bi thì phải bỏ vào đó hai viên bi khác màu, còn hộp chỉ chứa một viên bi thì bỏ vào đó viên bi có màu tùy ý.

Cho biết giá của một viên bi màu xanh là a đồng, viên bi màu đỏ là b đồng.

**Yêu cầu:** Tính số tiền ít nhất mà Tý cần có để mua bi bỏ đầy vào n hộp.

**Dữ liệu:** Vào từ tệp [COST.INP](https://COST.INP) gồm:

- Dòng đầu tiên chứa ba số nguyên dương n, a, b (1 ≤ n ≤ 10^6, 1 ≤ a, b ≤ 100).
    
- Dòng thứ hai chứa n số nguyên, mỗi số mang giá trị là 1 hoặc 2 tương ứng với số lượng bi mà các hộp có thể chứa được.
    

**Kết quả:** Ghi ra tệp [COST.OUT](https://COST.OUT) một số nguyên duy nhất là kết quả của bài toán.

**Ví dụ:**

- COST.INP:

```
5 3 9
2 1 1 2 1
```

- COST.OUT:

```
33
```

### Mã nguồn mẫu:

```cpp
#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int n, a, b, s;
int main()
{
    freopen("COST.inp","r",stdin);
    freopen("COST.out","w",stdout);
    cin >> n >> a >> b;
    for (int x, i=1; i<=n; i++)
    {
        cin >> x;
        if (x == 2) s += a + b;
        else s += min(a,b);
    }
    cout << s << endl;
    return 0;
}

```

- `for (int x, i=1; i<=n; i++)`: Vòng lặp từ 1 đến n để đọc giá trị của từng hộp.
    
    - `cin >> x;`: Đọc giá trị của hộp hiện tại.
        
    - `if (x == 2) s += a + b;`: Nếu hộp chứa 2 viên bi, cộng giá trị của a và b vào s.
        
    - `else s += min(a,b);`: Nếu hộp chứa 1 viên bi, cộng giá trị nhỏ hơn giữa a và b vào s.