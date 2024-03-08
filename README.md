# advancedC
# LECTURE 1 : COMPILER AND MACRO
**I.	COMPILER**

_**Quy trình biên dịch một chương trình C**_
-	Một ngôn ngữ cao hơn ngôn ngữ máy là ngôn ngữ Assembly. Đây là ngôn ngữ gần với ngôn ngữ máy nhất, từ Assembly có thể dịch ra ngôn ngữ máy để máy có thể hoạt động được.
-	C là một ngôn ngữ cấp cao hơn Assembly và từ C ta có thể biên dịch ra Assembly. C thì bị ràng buộc về cấu trúc, quy tắc nhưng việc đọc hiểu sẽ dễ dàng hơn và không phụ thuộc vào phần cứng. 
-	Vậy để chương trình C chạy được trên phần cứng nào thì ta cần phải biên dịch chương trình C thành ngôn ngữ máy để máy tính, vi điều khiển có thể hiểu được và thực hiện được chương trình như đã lập trình.
-	Quá trình biên dịch từ ngôn ngữ C thành ngôn ngữ máy được chia thành 5 bước: Tiền xử lý (Pre-processing), Biên dịch C (Compilation), Biên dịch Assembly (Assembling), Liên kết (Linking) và Tải (Loading).

> ![anh](https://github.com/sondt308/HomeWork/assets/143014005/52c29b50-9be3-4645-954b-d14a4d485b2e)

**1. Tiền xử lý (Pre-procesing)**

Giai đoạn tiền xử lý có nhiệm vụ xử lý các chỉ thị tiền xử lý (#define, #include, #if,…) và xóa các comment trong chương trình.
Một số ví dụ:
- Với #include, chương trình thay thế các tập tiêu đề vào mã nguồn.
- Với #define, thay thế macro, hằng số trực tiếp vào chương trình.
- Với #if, #ifdef, #else,. . . để chọn phần code nào sẽ được biên dịch dựa vào điều kiện của chỉ thị tiền xử lý.
Phần mở rộng của file đầu vào là .c, .h, và đầu ra của giai đoạn tiền xử lý là file .i.
Chương trình thực hiện giai đoạn tiền xử lý gọi là **Pre-processor**

**2. Biên dịch (Compilation)**

Đây là giai đoạn biên dịch chương trình C thành chương trình Assembly. Tại đây, trình biên dịch sẽ phát hiện các lỗi về cấu trúc, kiểu dữ liệu, cú pháp,. . . Nếu có lỗi thì quá trình dịch sẽ dừng lại và thông báo cho người dùng lỗi để người dùng chỉnh lại cho đúng.

Ngoài ra, một số thuật toán tối ưu code có thể được thực hiện tại đây nằm nâng cao hiệu quả hoạt động chương trình.
Phần mở rộng của file đầu vào là .i, và đầu ra là file .s.
Chương trình thực hiện quá trình dịch gọi là **Compiler**

**3. Biên dịch Assembly (Assembling)**

Quá trình biên dịch Assembly nhằm chuyển code Assembly thành mã máy được gọi là mã đối tượng (object code). Các object code sẽ chứa mã chương trình đã được biên dịch ra mã máy và các symbols là các hàm các biến. Lưu ý rằng các địa chỉ trong object code chỉ là địa chỉ tương đối dùng relative offsets. 

File này sẽ có dạng nhị phân có định dạng đặc biệt (a specially formatted binary file) gồm header và vài sections. Phần header sẽ định nghĩa mỗi section được section nào (text, data, bss).

Phần mở rộng của file đầu vào là .s, và đầu ra là file .o.

Chương trình thực hiện quá trình dịch assembly gọi là **Assembler**. Lưu ý rằng Assembler sẽ phụ thuộc vào kiến trúc của vi xử lý

**4.	Liên kết (Linking)**

Là quá trình liên kết các file đối tượng với nhau tạo thành file thực thi cuối cùng. Nó sẽ liên kết các file object code bằng cách thay thế các tham chiếu symbols bằng địa chỉ chính xác.

Ngoài ra, quá trình liên kết với các thư viện tĩnh (.a, .lib) cũng được liên kết tại giai đoạn này.

Phần mở rộng của file đầu vào là .o, và đầu ra tùy thuộc vào máy đích.

Chương trình thực hiện liên kết gọi là linker. **Linker** sẽ thực hiện các công việc sau:
- Tìm kiếm tất cả các định nghĩa của external function và biến toàn cục (global variables) từ tất cả các file object và các thư viện.
- Nó sẽ kết hợp các data section của các file object tạo thành 1 data section duy nhất.
- Nó sẽ kết hợp các code section của các file object tạo thành 1 code section duy nhất.
- Các địa chỉ sẽ được chỉnh lại phù hợp trong quá trình linking.

Nếu có bất kỳ lỗi nào được tìm ra trong quá trình liên kết thì sẽ không sinh ra được file thực thi. Các lỗi có thể xảy ra như không có hàm main() trong chương trình, không tìm được thư viện, không tìm thấy biến toàn cục, external function trong các file object.

**5.	Tải (Loading)**

Trên đây là các bước cơ bản để biên dịch một chương trình từ các file .c, .h thành chương trình thực thi. Quá trình tải lên sẽ khác nhau cho từng loại thiết bị chạy chương trình.

Nếu là máy tính chạy hệ điều hành windows thì file thực thi thường có đuôi là .exe được lưu trên ổ cứng. Khi nào có lệnh chạy chương trình thì mã chương trình được tải lên RAM chạy.

Nếu là máy tính chạy hệ điều hành linux thì file thực thi thường có đuôi là .out (hoặc không đuôi, tùy thuộc vào cách lưu của người dùng) được lưu trên ổ cứng. Khi nào có lệnh chạy chương trình thì mã chương trình được tải lên RAM chạy tương tự như windows.

Nếu là các vi điều khiển, chúng cần một chương trình của nhà sản xuất vi điều khiển để tải (load/flash/program) chương trình vào vi điều khiển.

**II. MACRO**

**1.**  Khi ta sử dụng chỉ thị **#include**, nội dung chứa trong header file sẽ được sao chép vào file hiện tại.

- Khi include sử dụng dấu ngoặc nhọn < > thì preprocessor sẽ được dẫn tới Include Directory của Compiler.

`#include <file>`

- Còn khi sử dụng dấu ngoặc kép thì preprocessor sẽ tìm kiếm file trong thư mục cùng chứa với file chương trình của bạn

`#include "file"
`

**2.**  Chỉ thị tiền xử lý **#define**
-Macro là một khái niệm dùng để định nghĩa một tập hợp các hướng dẫn tiền xử lý
-Dùng để thay thế một chuỗi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch.
-Giúp giảm lặp lại mã, dễ bảo trì chương trình.
-Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý #define

#include <stdio.h>

// Định nghĩa hằng số Pi sử dụng #define
#define PI 3.14
int main() {
    // Sử dụng hằng số Pi trong chương trình
    double radius = 5.0;
    double area = PI * radius * radius;

    printf("Radius: %.2f\n", radius);
    printf("Area of the circle: %.2f\n", area);

    return 0;
}

}
```
`Output: buffer size is 1020`

**3.** Macro có thể là hàm chứa các tham số, các tham số này sẽ không được kiểm tra kiểu dữ liệu.

Ví dụ, macro INCREMENT(x) ở dưới, x có thể là bất cứ kiểu dữ liệu nào.

```
#include <stdio.h>

// Định nghĩa hằng số Pi sử dụng #define
#define PI 3.14
int main() {
    // Sử dụng hằng số Pi trong chương trình
    double radius = 5.0;
    double area = PI * radius * radius;

    printf("Radius: %.2f\n", radius);
    printf("Area of the circle: %.2f\n", area);

    return 0;
}

```

