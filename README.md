<h3 align="center"> <img align="center" width="80%" src="https://github.com/user-attachments/assets/1f6cd1f5-9a0f-4019-ba8b-fb3594c2c9af" alt="HSG Tin"/> </h3>

<div align="center">
<br>
<a href="#theory"><kbd> <br> Lý thuyết <br> </kbd></a>&ensp;&ensp;
  <a href="#problems"><kbd> <br> Các đề chưa được giải <br> </kbd></a>&ensp;&ensp;
  <a href="https://github.com/baotrwg/HSG11-2025/tree/main/Solved"><kbd> <br> Các đề đã được giải <br> </kbd></a>&ensp;&ensp;
  <a href="#attention"><kbd> <br> Chú ý <br> </kbd></a>
</div><br>

## Theory:

### 🪧 Lý thuyết: 🪧

- [Đệ quy](#Đệ-quy)

- [Quay lui](#Quay-lui)

## Đệ-quy:

### I. Khái niệm về chương trình con đệ quy: 

- Ta nói một đối tượng được xác định bởi đệ qui nếu nó được xác định thông qua chính nó như một bộ phận.

- Ví dụ: Hàm tính giai thừa n! với n là một integer:

```
0! = 1
Nếu n>0 thì n! = n*(n-1)!
```

- Một chương trình con được gọi là đệ quy nếu trong quá trình thực hiện nó có phần phải gọi đến chính nó.

## II. Cấu trúc chính của một chương trình con đệ quy

- Một chương trình con đệ quy căn bản gồm **2 phần**:
	
	-  Phần cố định (phần neo): chứa các tác động của chương trình với một số giá trị cụ thể ban đầu của tham số.
	
	-  Hạ bậc (đệ qui): chứa các tác động cần được thực hiện cho giá trị hiện thời của tham số được định nghĩa bằng các tác động đã được thực hiện trước đây với kích thước nhỏ hơn của tham số.
- Ví dụ: 

	+ Hàm đệ qui tính n! 

```cpp
	long long GT(int n) {
		if (n == 0) {
			return 1;                   //cố định
	}
		else {
			return n * GT(n - 1);    //hạ bậc
	}
}
```

- Vòng lặp for tính n!

```cpp
	for (int i = 1; i <= n; i++) {
		gt = gt * i;
}
```

## III. Các bước giải bài toán đệ quy

-  Hiểu bài toán.

- Xác định trường hợp suy biến.

- Xác định bước đệ quy.

### Cấu trúc chung:

- **IF <Trường hợp suy biến>**
		**<Thực hiện công việc>**

- **ELSE**
		**<Tách bài toán thành bài toán đơn giản sử dụng đệ qui>**

## IV. Bài toán nào dùng đệ quy?

- **Phương pháp đệ quy thường áp dụng cho các bài toán phụ thuộc tham số có 2 đặc điểm sau:**
	
	- Bài toán dễ giải quyết trong một số trường hợp riêng ứng với các giá trị đặc biệt của tham số (**suy biến**).

	- Trong trường hợp tổng quát bài toán quy về các bài toán cùng dạng nhưng giá trị tham số bị thay số thay đổi và sau số lần hữu hạn các biến đổi đệ quy sẽ dẫn tới trường hợp suy biến (**đệ quy**).

## Quay-lui:

### I. Phương pháp:

Thuật toán quay lui xây dựng dần các thành phần của lời giải bằng cách thử mọi khả năng. Giả sử cần tìm lời giải với `n` thành phần `x₁, x₂,..., xₙ`. Nếu đã xác định được `i-1` thành phần (`x₁, x₂,..., xᵢ₋₁`), mục tiêu là xác định `xᵢ` bằng cách duyệt các khả năng.

Với mỗi khả năng `j`, kiểm tra xem nó có chấp nhận được không:

- **Nếu chấp nhận**, gán `xᵢ = j`. Nếu tìm thấy lời giải, ta có một cấu hình hoàn chỉnh. Nếu không, tiến hành xác định `xᵢ₊₁`.
    
- **Nếu không khả năng nào chấp nhận**, quay lui để xác định lại `xᵢ₋₁`.
    

Điểm quan trọng là ghi lại các khả năng đã thử để tránh trùng lặp, thường sử dụng cơ chế ngăn xếp (LIFO). Phương pháp này phù hợp với lập trình đệ quy.

Dưới đây là thủ tục đệ quy để xác định `xᵢ`:

```
Procedure Tim(i:integer); // tim xi
Var j:integer;
Begin
    <Xác định tập Si>
    for j∈Si do
        // if <chấp nhận j> then
        begin
            <xác định xi theo j> //x[i]=j
            if <tìm thấy nghiệm> then <ghi nhận một cấu hình>
            else Tim(i+1);
            <loại thành phần i>
        end;
end;
```

Phần quan trọng nhất trong thủ tục này là lập danh sách các khả năng và xác định giá trị của `< chấp nhận j >`. Giá trị này phụ thuộc vào `j` và các khả năng đã chọn trước đó tại `i-1`. Cần lưu lại trạng thái mới sau khi `< xác định xᵢ theo j >` và phục hồi trạng thái cũ sau `Tim(i+1)`. Các trạng thái này được lưu bằng một biến tổng thể (global), gọi là biến trạng thái.

Sau khi xây dựng thủ tục để qui Tim, đoạn chương trình chính giải bài toán liệt kê có dạng:

```
Begin Init; Tim(1); end;
```

Trong đó: Init là thủ tục khởi tạo các giá ban đầu (nhập các giá trị tham số của bài toán, khởi gán các biến trạng thái,...).

## Problems

### 👁️‍🗨️ Các đề chưa được giải:

- [Bạc Liêu 12 2023](#Bạc-Liêu)

## Bạc-Liêu:
**B1:**
![Câu 1:](./assets/1.png)  

**B2:**
![B2](./assets/2.png)

**B3:**
![B3](./assets/3.png)

## [Test case!](https://github.com/baotrwg/HSG11-2025/tree/main/Unsolved/THPT/B%E1%BA%A1c-Li%C3%AAu-12-2023/Cases)

## Attention 

### (Chú ý ⚠️):

> [!CAUTION]
> Tạo issue nếu có ý tưởng cần bàn 
> 
> Gửi mail tại: marino.kari24@gmail.com
> 
> Đây chỉ là trang chia sẻ kiến thức của các HS THPT (hoặc Sinh viên Đại Học).

> [!IMPORTANT]
> Không phải bài nào kết quả cũng tuyệt đối
> 
> Có thuật toán tối ưu hơn hoặc đề xuất xin hãy gửi trong issues

