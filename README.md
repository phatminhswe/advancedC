ADCANCED C
<details><summary> LECTURE 1 : COMPILER AND MACRO </summary>

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


![image](https://github.com/phatminhswe/advancedC/assets/162662273/a2e9224c-fa09-428d-8d8d-c7535b1dcb83)




**II. MACRO**

**1.**  Khi ta sử dụng chỉ thị **#include**, nội dung chứa trong header file sẽ được sao chép vào file hiện tại.

- Khi include sử dụng dấu ngoặc nhọn < > thì preprocessor sẽ được dẫn tới Include Directory của Compiler.

`#include <file>`

- Còn khi sử dụng dấu ngoặc kép thì preprocessor sẽ tìm kiếm file trong thư mục cùng chứa với file chương trình của bạn

`#include "file"`

**2.**  Chỉ thị tiền xử lý **#define**
- Macro là một khái niệm dùng để định nghĩa một tập hợp các hướng dẫn tiền xử lý
- Dùng để thay thế một chuỗi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch.
- Giúp giảm lặp lại mã, dễ bảo trì chương trình.
- Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý #define


```C
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

**3.** Macro có thể là hàm chứa các tham số.
```C
#include <stdio.h>

// Macro để tính bình phương của một số
#define SQUARE(x) ((x) * (x))

int main() {

    
    // Sử dụng macro để tính bình phương của num
    int result = SQUARE(5);

    printf("Result is: %d\n", result);

    return 0;
}

```

**4.** Preprocessor chỉ thực hiện thay thế các macro chứ không thực hiện các phép tính toán.

Ta có ví dụ như sau:

```C
#include <stdio.h>
#define CALC(X,Y) (X*Y)

int main() {
    printf("%d\n",CALC(1+2, 3+4));
    return 0;
}
```

```
Output:
11
```
Có thể thấy kết quả mong muốn là 21, tuy nhiên lại bằng 11.

Bởi vì các tham số sẽ được tính toán sau khi được thay thế nên macro CALC(1+2,3+4) sẽ trở thành (1+2*3+4) = (1+6+4) =(11).

Vậy để kết quả được tính đúng thì ta phải sửa lại như sau:

```C
#include <stdio.h>
// instead of writing X*Y, we write (X)*(Y)
#define CALC(X,Y) (X)*(Y)

int main() {
    printf("%d\n",CALC(1+2, 3+4));
    return 0;
}
```

```
Output:
21
```
**5.** Các tokens được truyền cho các macro có thể được nối bằng cách sử dụng toán tử ## (còn được gọi là toán tử Token-Pasting)

```C
#include <stdio.h>
#define merge(X,Y) X##Y

int main() {
    printf("%d\n",merge(12, 34));
    return 0;
}
```

```
Output:
1234
```
**6.** Một token được truyền cho macro có thể được chuyển thành một chuỗi kí tự bằng cách sử dụng dấu # trước nó

```C
#include <stdio.h>
#define convert(a) #a

int main() {
    printf("%s",convert(Hello));
    return 0;
}
```

```
Output:
Hello
```
**7.** Các macro có thể được viết trong nhiều dòng bằng cách sử dụng dấu ‘\’.

Dòng cuối cùng không cần có dấu ‘\’

```C
#include <stdio.h>

#define PRINT(i, limit) while (i < limit) { \
                            printf("Hello"); \
                            i++;             \
                         }

int main() {
    int i = 0; 
    PRINT(i, 3); 
    return 0;
}
```

```
Output:
HelloHelloHello
```
**8.** Nên hạn chế sử dụng các macro có các tham số vì chúng thỉnh thoảng có thể gây một số lỗi không mong muốn. Và inline function có thể sử dụng để thay thế.

Chúng ta theo dõi ví dụ dưới đây

```C
#include <stdio.h>
#define square(x) x*x

int main() {
    //Expanded as 36/6*6
    int x=36 / square(6);
    printf("%d",x);
    return 0;
}
```

```
Output:
36
```
Có thể thấy kết quả trả về đáng lẽ sẽ là bằng 1 nhưng nó lại bằng 36.

Nếu chúng ta sử dụng inline function, chúng ta sẽ được kết quả đúng như mong muốn

```C
#include <stdio.h>
static inline int square(int x) { return x*x; }

int main() {
    int x= 36/ square(6);
    printf("%d",x);
    return 0;
}
```

```
Output:
1
```
**9.** Chỉ thị tiền xử lý `#if, #elif, #else`

- `#if` sử dụng để bắt đầu một điều kiện tiền xử lý.
- Nếu điều kiện trong `#if` là đúng, các dòng mã nguồn sau `#if` sẽ được biên dịch
- Nếu sai, các dòng mã nguồn sẽ bị bỏ qua đến khi gặp `#endif`
- `#elif` dùng để thêm một điều kiện mới khi điều kiện trước đó trong `#if` hoặc `#elif` là sai
- `#else` dùng khi không có điều kiện nào ở trên đúng.
```C
#include <stdio.h>

typedef enum
{
    GPIOA,
    GPIOB,
    GPIOC
} Ports;

typedef enum
{
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} Pins;

typedef enum
{
    HIGH,
    LOW
} Status;

#define STM32 0
#define ATMEGA 1
#define PIC 2

#define MCU STM32

#if MCU == STM32
void daoTrangThaiDen(Ports port, Pins pin, Status status)
{
    if (status == HIGH)
    {
        HAL_GPIO_WritePin(port, pin, LOW);
    }
    else
    {
        HAL_GPIO_WritePin(port, pin, HIGH);
    }  
}
#elif MCU == ATMEGA
void daoTrangThaiDen(Pins pin, Status status)
{
    if (status == HIGH)
    {
        digitalWrite(pin, LOW);
    }
    else
    {
        digitalWrite(pin, HIGH);
    }  
}

#endif

void delay(int ms)
{

}


int main()
{
    while(1)
    {
        daoTrangThaiDen(GPIOA,13,HIGH);
        delay(1000);
    }

    return 0;
}

```
**10.** Chỉ thị tiền xử lý `#ifdef, #ifndef`

- `#ifdef` dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau `#ifdef` sẽ được biên dịch.
- `#ifndef` dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau `#ifndef` sẽ được biên dịch

abc.txt
```C
#ifndef __ABC_H
#define __ABC_H

int a = 10;

#endif
```
```C
#include <stdio.h>

#include "abc.txt"
#include "abc.txt"
#include "abc.txt"


int main()
{
    printf("Hello \n");
    
    return 0;
}

```
**11.** Một số toán tử Macro

**a)**
```C
#include <stdio.h>
#define STRINGIZE(x)
#define DATA 40
int main() {
// Sử dụng toán tử
printf("The value is: %s\n", STRINGIZE(DATA));
return 0;
}
```
```C
#include <stdio.h>
#define STRINGIZE_RESULT(x) STRINGIZE(x)
#define STRINGIZE(x) #x#define DATA 40
int main() {
// Sử dụng toán tử #
printf("The value is: %s\n", STRINGIZE_RESULT(DATA));
return 0;
}

```
**b)**
```C
#include <stdio.h>
#define DECLARE_VARIABLE(prefix, number)

int prefix##number

int main() {
// Sử dụng macro để khai báo các biến động
DECLARE_VARIABLE(var, 1); // int var1;
DECLARE_VARIABLE(var, 2); // int var2;
// Gán giá trị cho các biến
var1 = 10;
var2 = 20;
// In ra giá trị của các biến
printf("var1: %d\n", var1);
printf("var2: %d\n", var2);
return 0;
}

```
**c)**
```C
#include <stdio.h>

void feature1() { printf("Feature 1 selected\n"); }
void feature2() { printf("Feature 2 selected\n"); }
void feature3() { printf("Feature 3 selected\n"); }
void feature4() { printf("Feature 4 selected\n"); }


int main()
{
    printf("1. Option 1\n");
    printf("2. Option 2\n");
    printf("3. Option 3\n");
    printf("4. Option 4\n");
    printf("5. Exit\n");

    // Giả sử option được nhập từ người dùng
    int option ;
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        feature1();
        break;
    case 2:
        feature2();
        break;
    case 3:
        feature3();
        break;
    case 4:
        feature4();
        break;
    default:
        printf("Invalid option");
        break;
    }
    return 0;
}


```
```C
#include <stdio.h>
#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)
#define PRINT_MENU(...) \
    do { \
        const char* items[] = {__VA_ARGS__}; \
        int n = sizeof(items) / sizeof(items[0]); \
        for (int i = 0; i < n; i++) { \
            PRINT_MENU_ITEM(i + 1, items[i]); \
        } \
    } while (0)
```
```C
#define CASE_OPTION(number, function) case number: function(); break;
#define HANDLE_OPTION(option, ...) \
    switch (option) { \
        __VA_ARGS__ \
        default: printf("Invalid option!\n"); \
    }


void feature1() { printf("Feature 1 selected\n"); }
void feature2() { printf("Feature 2 selected\n"); }
void feature3() { printf("Feature 3 selected\n"); }
void feature4() { printf("Feature 4 selected\n"); }
```
```C
int main()
{
    PRINT_MENU("Option 1", "Option 2", "Option 3","Option4", "Exit");

    // Giả sử option được nhập từ người dùng
    int option ;
    scanf("%d", &option);

    HANDLE_OPTION(option,
        CASE_OPTION(1, feature1)
        CASE_OPTION(2, feature2)
        CASE_OPTION(3, feature3)
        CASE_OPTION(4, feature4)

     
    )
    return 0;
}
```

**12.** Chỉ thị tiền xử lý `#undef`


- Chỉ thị `#undef` dùng để hủy định nghĩa của một macro đã được định nghĩa trước đó bằng `#define`
```C
#include <stdio.h>
// Định nghĩa SENSOR_DATA 
#define SENSOR_DATA 42
int main() {
printf("Value of MY_MACRO: %d\n", MY_MACRO);
// Hủy định nghĩa SENSOR_DATA 
#undef SENSOR_DATA 
// Định nghĩa SENSOR_DATA 
#define SENSOR_DATA 50
printf("Value of MY_MACRO: %d\n", MY_MACRO);
return 0;
}
```
- Chúng ta có thể bỏ định nghĩa các macro đã định nghĩa trước đó bằng cách sử dụng #undef

```C
#include <stdio.h>
#define NUMBER 212

int main() {
    printf("%d", NUMBER);
#undef NUMBER
    printf("%d", NUMBER);
    return 0;
}
```

Chương trinh này sẽ có lỗi tại dòng thứ 7 vì NUMBER chưa được định nghĩa. Ta sẽ chỉnh lại như sau:

```C
#include <stdio.h>
#define NUMBER 212

int main() {
    printf("%d\n", NUMBER);
#undef NUMBER
    int NUMBER = 100;
    printf("%d", NUMBER);
    return 0;
}
```

```
Output
212 
100
```

</details>
<details><summary> LECTURE 2 : TDARG - ASSERT </summary>


**I.Thư viện stdarg**
- Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.
- Các hàm như printf và scanf là ví dụ điển hình 
**Stddarg Function**
- va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
- va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
- va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

```c
#include <stdio.h>
#include<stdarg.h>
int MUL(int arr,...){
int val=1;
va_list ap;
va_start(ap,arr);
for (int i = 0; i < arr; i++)
{
val *= va_arg(ap,int);
}
va_end(ap);
return val;
}
int main(int argc, char const *argv[])
{
printf("MUX:%d",MUL(4,2,2,2,2));
return 0;
}
```
OUTPUT
```c
MUX:16
```
**II.Thư viện assert**
- Cung cấp macro assert. 
- Macro này được sử dụng để kiểm tra một điều kiện. 
- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
- Dùng trong debug, dùng #define NDEBUG để tắt debug

- Điều kiện đúng
 ```c
#include <stdio.h>
#include <assert.h>
int main() {
    int x = 5;

    assert(x == 5);

    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
    printf("X is: %d", x);
    
    return 0;
}
```
```c
X is: 5
```

-Điều kiện sai

```c
#include <stdio.h>
#include <assert.h>

int main() {
    int x = 5;

    assert(x == 10);

    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
    printf("X is: %d", x);
    
    return 0;
}
```
```c
Assertion failed: x == 10, file main.c, line 7
```
**Các lỗi**
- Lỗi truy cập mảng không an toàn.
- Lỗi chia cho số 0.
- Chia số nguyên cho số nguyên, kết quả là số thực.

EX1
```c
#include <assert.h>

#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level) {
    ASSERT_IN_RANGE(level, 1, 10);
    // Thiết lập cấp độ
}
```

EX2
```c
#include <assert.h>
#include <stdint.h>

#define ASSERT_SIZE(type, size) assert(sizeof(type) == (size))

void checkTypeSizes() {
    ASSERT_SIZE(uint32_t, 4);
    ASSERT_SIZE(uint16_t, 2);
    // Kiểm tra các kích thước kiểu dữ liệu khác
}
```

</details>
<details><summary> LECTURE 3 : POINTER </summary>


- Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số khái niệm cơ bản về con trỏ trong C:

![image](https://github.com/phatminhswe/advancedC/assets/162662273/35130344-62a1-45c2-baaf-1db96081131b)


- Cách khai báo:
```C
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float

```
- Lấy địa chỉ của một biến và truy cập giá trị:
```C
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
int y = *ptr_x;  // y sẽ bằng giá trị của x

```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch

```C
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));
    return 0;
}

```
- Ứng dụng:

```C
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
}


```

**Void Pointer**
- Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

```C
void *ptr_void;

```
```C
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}
```
**Function Pointer**
- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
**EX:**
```C
#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```
**EX:**
```C
include <stdio.h>

void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
}

void calculator(void (*ptr)(int, int), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}


int main()
{
    calculator(sum,5,2);
    calculator(subtract,5,2);
    calculator(multiple,5,2);
    calculator(divide,5,2);

    //void (*ptr[])(int, int) = {sum, divide, multiple};
    //ptr[0](5,6);

    return 0;
}

```

**EX:**

```C
#include <stdio.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)     
        for (j = i+1; j < n; j++) 
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

```
**Pointer to Constant**
-Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
```
int const *ptr_const; 
const int *ptr_const;
```
**EX:**
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int value = 5;
    int const *ptr_const = &value;

    //*ptr_const = 7; // wrong
    //ptr_const++; // right
    
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);

    return 0;
}

```

**Constant Pointer**

- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
```
int *const const_ptr = &value;

```
**EX:**
```C
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    //const_ptr = &test; // wrong
    
    return 0;
}
```

**Pointer to Pointer**
- Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.


![image](https://github.com/phatminhswe/advancedC/assets/162662273/1d28aecb-b509-49a6-8dc8-d4399919ac14)


**EX:**
```C
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);

    printf("dereference ptr2 second time: %d\n", **ptr2);

    return 0;
}

```
**NULL Pointer**

- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.
**EX:**
```C
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
    

    return 0;
}

```

</details>
<details><summary>  LECTURE 4 : Memory layout </summary>



**Memory layout**

-Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.


![image](https://github.com/phatminhswe/advancedC/assets/162662273/e03f680a-7462-401d-a3f5-6a25013a02c6)


**Text segment**

Mã máy:
- Chứa tập hợp các lệnh thực thi.
- Quyền truy cập: Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. 
- Lưu hằng số, con trỏ kiểu char.
- Tất cả các biến lưu ở phần vùng Text đều không thể thay đổi giá trị mà chỉ được đọc.
```C
#include <stdio.h>

const int a = 10;
char arr[] = "Hello";
char *arr1 = "Hello";

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);

    arr1[3] = 'E';
    printf("arr1: %s", arr1);

    
    return 0;
}

```
**Data segment**
Initialized Data Segment (Dữ liệu Đã Khởi Tạo):
- Chứa các biến toàn cục được khởi tạo với giá trị khác 0.
- Chứa các biến static được khởi tạo với giá trị khác 0.
- Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến .
- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.

  **EX:**
 ```C 
#include <stdio.h>
int a = 10;
double d = 20.5;

static int var = 5;

void test()
{
    static int local = 10;
}


int main(int argc, char const *argv[])
{  
    a = 15;
    d = 25.7;
    var = 12;
    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);



    return 0;
}
```

**Bss segment**
Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):
- Chứa các biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị.
- Chứa các biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị.
- Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến .
- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.

#include <stdio.h>


typedef struct 
{
    int x;
    int y;
} Point_Data;


int a = 0;
int b;

static int global = 0;
static int global_2;

static Point_Data p1 = {5,7};

**EX:**
```C
void test()
{
    static int local = 0;
    static int local_2;
}

int main() {

    
    printf("a: %d\n", a);
    printf("global: %d\n", global);
   

    
    
    return 0;
}
```

**Stack**

- Chứa các biến cục bộ, tham số truyền vào.
- Quyền truy cập: đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.
- Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ.

```C
#include <stdio.h>


void test()
{
    int test = 0;
    test = 5;
    printf("test: %d\n",test);
}

int sum(int a, int b)
{
    int c = a + b;
    printf("sum: %d\n",c);
    return c;
}



int main() {

    sum(3,5);
    /*
        0x01
        0x02
        0x03
    */
   test();
   /*
    int test = 0; // 0x01
   */


    
    return 0;
}


```


**Heap**

![image](https://github.com/phatminhswe/advancedC/assets/162662273/b438a1ec-5944-4ed6-958a-0ff201c37a8b)


```C
#include <stdio.h>
#include <stdint.h>

uint32_t arr[] = {2,3,5,6,8}; 


int main() {

    for (int i = 0; i < 5; i++)
    {
        printf("Address: %p\n", arr +i);
        printf("Value: %d\n", *(arr+i));
    }
    

    
    return 0;
}

```


Cấp phát động:
- Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
- Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
- Các hàm như malloc(), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.

`malloc()`:
-Tham số truyền vào: kích thước mong muốn ( byte)
-Giá trị trả về: con trỏ void

**EX:**
```C
#include <stdlib.h>

int main() {
    int *arr_malloc, *arr_calloc;
    size_t size = 5;

    // Sử dụng malloc
    arr_malloc = (int*)malloc(size * sizeof(int));

    // Sử dụng calloc
    arr_calloc = (int*)calloc(size, sizeof(int));

    // ...

    // Giải phóng bộ nhớ
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}

```
**EX:**
```C
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;

    char* ten = (char*) malloc(sizeof(char) * soluongkytu);



    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);

        printf("Hello %s\n", ten);
    }
    

    

    return 0;
}

```

- Quyền truy cập: có quyền đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.

**Stack và Heap**

- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.
- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.
**EX:**
  
```C
#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int array[3];
    for (int i = 0; i < 3; i++)
    {
        printf("address of array[%d]: %p\n", i, (array+i));
    }
    printf("----------------------\n");
}

void test2()
{
    int *array = (int*)malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("address of array[%d]: %p\n", i, (array+i));
    }
    printf("----------------------\n");
    //free(array);
}



int main(int argc, char const *argv[])
{  
    test1();
    test1();
    test2();
    test2();



    return 0;
}

```
- Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
```
int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
}

```
- Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

```
int *A = (int *)malloc(18446744073709551615);
```


</details>
<details><summary>  LECTURE 5 : Extern - Static - Volatile - Register </summary>

# Extern

- Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
  
# Static
- Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
```c
#include<stdio.h>
 
int in_so_thu_tu(void)
{
   static int x = 0;
   x = x + 1;
   printf("%d\r\n",x);
} 
 
int main() {
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 0
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 1
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 2
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 3
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 4
   return 0;
}
```
```
Kết quả:
1
2
3
4
5
```
Biến static trong khai báo biến toàn cục và khai báo hàm

Mỗi project thường sẽ được viết trên nhiều File vì mục đích phân chia module cũng như là để dễ bảo trì. Do có nhiều File nên rất có thể ở các File sẽ có sự trùng lặp trong cách đặt tên biến. Để tránh sự cố sai sót này người ta đưa ra khái niệm biến toàn cục tĩnh và hàm tĩnh.

- Biến toàn cục tĩnh sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.
- Hàm tĩnh sẽ chỉ có thể gọi trong File khai báo nó, các File khác không có cách nào gọi hàm này được.
```
Ví dụ:
//-----------------
//A.c

// biến a này chỉ được sử dụng trong file A.c
static int a;    

// hàm hienthi() này chỉ được sử dụng trong file A.c
static void hien_thi() {};   

int c;


//------------------
//B.c

// biến a này chỉ được sử dụng trong file B.c
static int a;    

// hàm hienthi() này chỉ được sử dụng trong file B.c
static void hien_thi() {};

int d; 
```
# Volatile
- Trong lập trình nhúng (Embedded System), ta rất thường hay gặp khai báo biến với từ khóa volatile. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.
- Volatile đại diện cho các biến có thể thay đổi bất thường mà không thông qua nguồn source code.

```c
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
	
	while(1)
	{
		i = *((int*) 0x20000000);
		if (i > 0)
		{
			break;
		}
		
	}
	a = 200;
}
```

Ví dụ: 
Trong lập trình nhúng, chúng ta hay gặp đoạn code khi ta khai báo 1 biến đếm count, mỗi khi bấm nút xảy ra ngắt ngoài, chúng ta tăng biến đếm count. Tuy nhiên, khi chúng ta bật tính năng tối ưu code của compiler, nó sẽ hiểu rằng các biến như vậy dường như không thay đổi giá trị bởi phần mềm nên compiler có xu hướng loại bỏ biến count để có thể tối ưu kích cỡ file code chạy được sinh ra.

# Register
- Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.


![image](https://github.com/phatminhswe/advancedC/assets/162662273/8350ec21-190c-4aa0-a9f5-4e407445050a)


```c
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();
    int i;

    // Đoạn mã của chương trình
    for (i = 0; i < 2000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}

```
</details>
<details><summary>  LECTURE 6 : Goto - setjmp.h </summary>

# Goto
Câu lệnh goto trong C cung cấp một bước nhảy vô điều kiện từ 'goto' đến một câu lệnh có nhãn trong cùng một hàm.

Chú ý: Việc sử dụng câu lệnh goto không được khuyến khích sử dụng trong bất kỳ ngôn ngữ lập trình nào vì nó rất khó để theo dõi luồng điều khiển của chương trình, làm cho chương trình khó hiểu và khó bảo trì.
- Cú pháp
```
goto ten_nhan;
..
.
ten_nhan: lenh;
```

![image](https://github.com/phatminhswe/advancedC/assets/162662273/74404500-7205-47a7-af56-851a16b6c471)
**EX:**
```c
// kiểm tra 1 số là số chẵn hay số lẻ
#include <stdio.h> 
 
// function to check even or not 
void checkEvenOrNot(int num) 
{ 
   if (num % 2 == 0)  // số chẵn
       goto even; 
   else               // số lẻ
       goto odd; 
 
even: 
   printf("%d là số chẵn", num); 
   return; // return nếu không chương trình sẽ chạy tiếp xuống bên dưới
odd: 
   printf("%d là số lẻ", num); 
} 
 
int main() { 
   int num = 26; 
   checkEvenOrNot(num); 
   return 0; 
} 
```
```
26 là số chẵn
```
Ở chương trình trên chúng ta thấy có 2 nhãn dãn để nhảy vào. Khi chương trình kiểm tra 1 số là số chẵn hay số lẻ nó sẽ nhảy vào nhãn dãn tương ứng để xử lý.

Chú ý nếu không có return chương trình sẽ tiếp tục chạy tiếp xuống các dòng lệnh bên dưới. Vì goto hiểu đơn giản chỉ là trỏ chương trình nhảy tới 1 vị trí chúng ta đã đặt sẵn.
**EX:**
```C
#include <stdio.h> 
 
// in ra các số từ 1 đến 10
void printNumbers() 
{ 
   int n = 1; 
label: 
   printf("%d ",n); 
   n++; 
   if (n <= 10)   // nếu n <= 10 nhảy đến vị trí nhãn dãn label
       goto label; 
} 
 
int main() { 
   printNumbers(); 
   return 0; 
} 
```
```
Kết quả: 1 2 3 4 5 6 7 8 9 10
```
# setjmp.h

Header file có tên setjmp.h trong Thư viện C định nghĩa macro setjmp(), một hàm longjmp(), và một kiểu biến jmp_buf, để bỏ qua lời gọi hàm thông thường và trả về qui tắc, bằng cách cung cấp các phương thức để thực hiện các cú nhảy mà vẫn duy trì môi trường gọi hàm.

**Biến được định nghĩa trong setjmp.h**

Dưới đây là kiểu biến được định nghĩa trong setjmp.h:

jmp_buf: Đây là một kiểu mảng được sử dụng để giữ thông tin cho macro setjmp() và hàm longjmp().

**Các macro được định nghĩa trong setjmp.h**

Chỉ có một macro được định nghĩa trong thư viện này:

int setjmp(jmp_buf environment): Macro này lưu trữ môi trường (environment) hiện tại bên trong biến environment để sử dụng sau bởi hàm longjmp(). Nếu macro này trả về một cách trực tiếp từ lời gọi macro, thì nó trả về 0; nhưng nếu nó trả về từ một lời gọi hàm longjmp(), thì một giá trị khác 0 được trả về.

**Khai báo Macro setjmp() trong C**

Dưới đây là phần khai báo cho setjmp() macro.

```
int setjmp(jmp_buf environment)
```
- Tham số:

environment − Đây là đối tượng của kiểu jmp_buf nơi mà thông tin về môi trường được lưu trữ.

- Trả về giá trị:

Macro này trả về nhiều hơn 1 lần. Đầu tiên, trên lời gọi trực tiếp của nó, nó luôn luôn trả về 0. Khi longjmp được gọi với thông tin được thiết lập tới environment, macro này lại trả về lần nữa; lúc này nó trả về giá trị đã được truyền tới longjmp như là tham số thứ hai.

**Các hàm được định nghĩa trong setjmp.h**
Chỉ có một hàm được định nghĩa trong setjmp.h:

Hàm void longjmp(jmp_buf environment, int value): Hàm này phục hồi môi trường (environment) đã được lưu trữ bởi lời gọi gần nhất tới macro setjmp() trong cùng lời gọi hàm của chương trình với tham số tương ứng là jmp_buf.

**Khai báo hàm longjmp() trong C**

Dưới đây là phần khai báo cho hàm longjmp() trong C:
```
void longjmp(jmp_buf environment, int value)
```
- Tham số:

environment − Đây là đối tượng của kiểu jmp_buf chứa thông tin để lưu trữ môi trường tại điểm gọi của setjmp.
value − Đây là giá trị để biểu thức setjmp ước lượng.

- Trả về giá trị:

Hàm này không trả về bất cứ giá trị nào.


</details>
<details><summary>  LECTURE 7 : Bitmask </summary>

- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.


**NOT bitwise**
```
int result = ~num ;
```
Kết quả là bit đảo ngược của số đó.


**AND bitwise**

```
int result = num1 & num2;
```
Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.


**OR bitwise**
```
int result = num1 | num2;
```
Kết quả là 1 nếu có hơn một bit tương ứng là 1.


**XOR bitwise**	
```
int result = num1 ^ num2;

```
Kết quả là 1 nếu chỉ có một bit tương ứng là 1.
**Shift left và Shift right bitwise**
- Dùng để di chuyển bit sang trái hoặc sang phải.
- Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
- Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).

```
int resultLeftShift = num << shiftAmount;
int resultRightShift = num >> shiftAmount;
```


**EX:**
```C
#include <stdio.h>
#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

typedef struct {
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;
void displayAllStatusLed(LEDStatus status) {
 	uint8_t* statusPtr = (uint8_t*)&status;
		for (int j = 0; j < 8; j++) {
		printf("LED%d: %d\n", j+1, (*statusPtr >> j) & 1);
}

}


int main() {
    LEDStatus ledStatus = {.LED7 = ENABLE};

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;
    displayAllStatusLed(ledStatus);
	
    return 0;
}
```
</details>
<details><summary> LECTURE 8 : Struct - Union </summary>


- struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.

syntax :
 
```
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};

```

**Kích thước của struct**
```c
struct Example {
    uint8_t a;  // blue  
    uint16_t b; // green
    uint32_t c; // yellow 
}; 
```

![image](https://github.com/phatminhswe/advancedC/assets/162662273/0f06e45f-0b0e-4263-9382-3b795ef7cfd2)

```c
struct Example {
    uint8_t a;     // blue  
    uint32_t b;    // green
    uint16_t c;    // yellow  
};
```

![image](https://github.com/phatminhswe/advancedC/assets/162662273/462296b3-b8b5-49dc-bcbc-3ef249b36c6e)

```c
struct Example1 {
    uint8_t arr1[5]; // blue
    uint16_t arr2[4]; // green   
uint32_t arr3[2];      // yellow		
};
```

![image](https://github.com/phatminhswe/advancedC/assets/162662273/f5526a12-3e4b-4bf4-98da-401b37cc6899)

- union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.

syntax :

```c
union TenUnion {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```

**Kích thước union**

```c
union Data {  //4byte
    uint8_t a;
    uint16_t b;
    uint32_t c;
};  
```

**Ứng dụng kết hợp struct và union**

```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;


int main(int argc, char const *argv[])
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

		Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
	
    
    return 0;
}
```



</details>


<details><summary> LECTURE 9 : Json </summary>

JSON (JavaScript Object Notation) là một định dạng dữ liệu dựa trên văn bản (text-based), được sử dụng để truyền và lưu trữ dữ liệu giữa các ứng dụng. JSON được thiết kế để dễ đọc và dễ hiểu cho con người, cũng như dễ phân tích và tạo ra bằng các ngôn ngữ lập trình.

JSON được tổ chức dưới dạng các cặp key-value (khóa-giá trị), trong đó mỗi khóa là một chuỗi và mỗi giá trị có thể là một số, một chuỗi, một đối tượng JSON khác hoặc một mảng JSON.

**a, JSON Values**

In JSON, values must be one of the following data types:

- a string (must be written in double quotes) -> Ex: {"name":"John"}
  
- a number (must be an integer or a floating point) -> Ex: {"age":30}
  
- an object (Values in JSON can be objects) -> Ex: { "employee":{"name":"John", "age":30, "city":"New York"} }
  
- an array -> Ex: { "employees":["John", "Anna", "Peter"] }
  
- a boolean -> Ex: {"sale":true}

- null -> Ex: {"middlename":null}

JSON values cannot be one of the following data types: a function a date undefined

**b, JSON Objects**
```c
	{ "name": "Bob Johnson", "age": 35, "city": "Chicago" },
	{ "name": "John Doe", "age": 30, "city": "New York", "occupation": "Software Engineer", "isStudent": false },
	{
	    "name": "Jane Smith",
	    "age": null,
	    "city": "Los Angeles",
	    "contact": { "email": "jane.smith@example.com", "phone": "555-1234" }
	}
```
**EX**
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stddef.h>
	#include <ctype.h>
	#include <stdbool.h>
	
	typedef enum {
	    JSON_NULL,
	    JSON_BOOLEAN,
	    JSON_NUMBER,
	    JSON_STRING,
	    JSON_ARRAY,
	    JSON_OBJECT
	} JsonType;
	
	typedef struct JsonValue {
	    JsonType type;
	    union {
	        int boolean; double number; char *string;
	        struct {
	            struct JsonValue *values;
	            size_t count; // số lượng element
	        } array;
	        struct {
	            char **keys;
	            struct JsonValue *values;
	            size_t count; // số cặp key-value
	        } object;
	    } value;
	} JsonValue;
	
	JsonValue *parse_json(const char **json);
	
	void free_json_value(JsonValue *json_value);
	
	static void skip_whitespace(const char **json) {
	    while (isspace(**json)) {
	        (*json)++;
	    }
	}
	
	JsonValue *parse_null(const char **json) {
	    skip_whitespace(json);
	    if (strncmp(*json, "null", 4) == 0) { // khi bắt gặp đc chữ n -> nó lấy thêm 3 phần tử tiếp theo -> so sánh với null
	        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	        value->type = JSON_NULL; 
	        *json += 4;
	        return value;
	    }
	    return NULL;
	}
	
	JsonValue *parse_boolean(const char **json) {
	    skip_whitespace(json);
	    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	    if (strncmp(*json, "true", 4) == 0) {
	        value->type = JSON_BOOLEAN;
	        value->value.boolean = true;
	        *json += 4;
	    } else if (strncmp(*json, "false", 5) == 0) {
	        value->type = JSON_BOOLEAN;
	        value->value.boolean = false;
	        *json += 5;
	    } else {
	        free(value);
	        return NULL;
	    }
	    return value;
	}
	
	JsonValue *parse_number(const char **json) {
	    skip_whitespace(json);
	    char *end; //:') 
	
	    double num = strtod(*json, &end);
	    if (end != *json) {
	        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	        value->type = JSON_NUMBER;
	        value->value.number = num;
	        *json = end;
	        return value;
	    }
	    return NULL;
	}
	
	JsonValue *parse_string(const char **json) {
	    skip_whitespace(json);
	
	    if (**json == '\"') {
	        (*json)++;
	        const char *start = *json;
	        while (**json != '\"' && **json != '\0') {
	            (*json)++;
	        }
	        if (**json == '\"') {
	            size_t length = *json - start; // 3
	            char *str = (char *) malloc((length + 1) * sizeof(char));
	            strncpy(str, start, length);
	            str[length] = '\0';
	
	            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	            value->type = JSON_STRING;
	            value->value.string = str;
	            (*json)++;
	            return value;
	        }
	    }
	    return NULL;
	}
	
	JsonValue *parse_array(const char **json) {
	    skip_whitespace(json);
	    if (**json == '[') {
	        (*json)++;
	        skip_whitespace(json);
	
	        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
	        array_value->type = JSON_ARRAY;
	        array_value->value.array.count = 0;
	        array_value->value.array.values = NULL;
	
	        /*
	        double arr[2] = {};
	        arr[0] = 30;
	        arr[1] = 70;
	        */
	
	        while (**json != ']' && **json != '\0') {
	            JsonValue *element = parse_json(json); // 70
	            if (element) {
	                array_value->value.array.count++;
	                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
	                array_value->value.array.values[array_value->value.array.count - 1] = *element;
	                free(element);
	            } else {
	                break;
	            }
	            skip_whitespace(json);
	            if (**json == ',') {
	                (*json)++;
	            }
	        }
	        if (**json == ']') {
	            (*json)++;
	            return array_value;
	        } else {
	            free_json_value(array_value);
	            return NULL;
	        }
	    }
	    return NULL;
	}
	
	JsonValue *parse_object(const char **json) {
	    skip_whitespace(json);
	    if (**json == '{') {
	        (*json)++;
	        skip_whitespace(json);
	
	        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
	        object_value->type = JSON_OBJECT;
	        object_value->value.object.count = 0;
	        object_value->value.object.keys = NULL;
	        object_value->value.object.values = NULL;
	
	        while (**json != '}' && **json != '\0') {
	            JsonValue *key = parse_string(json);
	            if (key) {
	                skip_whitespace(json);
	                if (**json == ':') {
	                    (*json)++;
	                    JsonValue *value = parse_json(json);
	                    if (value) {
	                        object_value->value.object.count++;
	                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
	                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;
	
	                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
	                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
	                        free(value);
	                    } else {
	                        free_json_value(key);
	                        break;
	                    }
	                } else {
	                    free_json_value(key);
	                    break;
	                }
	            } else {
	                break;
	            }
	            skip_whitespace(json);
	            if (**json == ',') {
	                (*json)++;
	            }
	        }
	        if (**json == '}') {
	            (*json)++;
	            return object_value;
	        } else {
	            free_json_value(object_value);
	            return NULL;
	        }
	    }
	    return NULL;
	}
	
	JsonValue *parse_json(const char **json) { // làm việc với giá trị json_str_value 
	    while (isspace(**json)) {
	        (*json)++;
	    }
	
	    switch (**json) {
	        case 'n':
	            return parse_null(json);
	        case 't':
	        case 'f':
	            return parse_boolean(json);
	        case '\"':
	            return parse_string(json);
	        case '[':
	            return parse_array(json);
	        case '{':
	            return parse_object(json);
	        default:
	            if (isdigit(**json) || **json == '-') return parse_number(json);
	            else return NULL; // Lỗi phân tích cú pháp
	    }
	}
	
	void free_json_value(JsonValue *json_value) {
	    if (json_value == NULL) return;
	    
	    switch (json_value->type) {
	        case JSON_STRING:
	            free(json_value->value.string);
	            break;
	        case JSON_ARRAY:
	            for (size_t i = 0; i < json_value->value.array.count; i++) {
	                free_json_value(&json_value->value.array.values[i]);
	            }
	            free(json_value->value.array.values);
	            break;
	        case JSON_OBJECT:
	            for (size_t i = 0; i < json_value->value.object.count; i++) {
	                free(json_value->value.object.keys[i]);
	                free_json_value(&json_value->value.object.values[i]);
	            }
	            free(json_value->value.object.keys);
	            free(json_value->value.object.values);
	            break;
	        default:
	            break;
	    }
	}
	
	void test(JsonValue* json_value){
	    if (json_value != NULL && json_value->type == JSON_OBJECT) {
	        // Truy cập giá trị của các trường trong đối tượng JSON
	        size_t num_fields = json_value->value.object.count;
	        size_t num_fields2 = json_value->value.object.values->value.object.count;
	        for (size_t i = 0; i < num_fields; ++i) {
	
	            char* key = json_value->value.object.keys[i];
	            JsonValue* value = &json_value->value.object.values[i];
	
	            JsonType type = (int)(json_value->value.object.values[i].type);
	
	            if(type == JSON_STRING) printf("%s: %s\n", key, value->value.string);
	        
	            if(type == JSON_NUMBER) printf("%s: %f\n", key, value->value.number);
	        
	            if(type == JSON_BOOLEAN) printf("%s: %s\n", key, value->value.boolean ? "True":"False");
	
	            if(type == JSON_OBJECT){
	                printf("%s: \n", key);
	                test(value);
	            }
	
	            if(type == JSON_ARRAY){
	                printf("%s: ", key);
	                for (int i = 0; i < value->value.array.count; i++) {
	                   test(value->value.array.values + i);
	                } 
	                printf("\n");
	            }
	        }
	    } else {
		    if(json_value->type == JSON_STRING) printf("%s ", json_value->value.string);
		    
		    if(json_value->type == JSON_NUMBER) printf("%f ", json_value->value.number);
		
		    if(json_value->type == JSON_BOOLEAN) printf("%s ", json_value->value.boolean ? "True":"False");
		
		    if(json_value->type == JSON_OBJECT){
			printf("%s: \n", json_value->value.object.keys);
			test(json_value->value.object.values);          
	            }
	      }
	}
	
	int main(int argc, char const *argv[]) {
	     
	     // Chuỗi JSON đầu vào
	    const char* json_str = "{"
	                        "\"1001\":{"
	                          "\"SoPhong\":3,"
	                          "\"NguoiThue\":{"
	                            "\"Ten\":\"Nguyen Van A\","
	                            "\"CCCD\":\"1920517781\","
	                            "\"Tuoi\":26,"
	                            "\"ThuongTru\":{"
	                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
	                              "\"Phuong_Xa\":\"Phuong 6\","
	                              "\"Tinh_TP\":\"Ho Chi Minh\""
	                            "}"
	                          "},"
	                          "\"SoNguoiO\":{"
	                            "\"1\":\"Nguyen Van A\","
	                            "\"2\":\"Nguyen Van B\","
	                            "\"3\":\"Nguyen Van C\""
	                          "},"
	                          "\"TienDien\": [24, 56, 98],"
	                          "\"TienNuoc\":30.000"
	                        "},"
	                        "\"1002\":{"
	                          "\"SoPhong\":5,"
	                          "\"NguoiThue\":{"
	                            "\"Ten\":\"Phan Hoang Trung\","
	                            "\"CCCD\":\"012345678912\","
	                            "\"Tuoi\":24,"
	                            "\"ThuongTru\":{"
	                              "\"Duong\":\"53 Le Dai Hanh\","
	                              "\"Phuong_Xa\":\"Phuong 11\","
	                              "\"Tinh_TP\":\"Ho Chi Minh\""
	                            "}"
	                          "},"
	                          "\"SoNguoiO\":{"
	                            "\"1\":\"Phan Van Nhat\","
	                            "\"2\":\"Phan Van Nhi\","
	                            "\"2\":\"Phan Van Tam\","
	                            "\"3\":\"Phan Van Tu\""
	                          "},"
	                          "\"TienDien\":23.000,"
	                          "\"TienNuoc\":40.000"
	                        "}"
	                      "}";
	    
	
	    // Phân tích cú pháp chuỗi JSON
	    JsonValue* json_value = parse_json(&json_str);
	
	   test(json_value);
	
	    // Kiểm tra kết quả phân tích cú pháp
	
	       // Giải phóng bộ nhớ được cấp phát cho JsonValue
	    free_json_value(json_value);
	    
	        //printf("test = %x", '\"');
	
	       // hienthi(5);
	    
	    return 0;
	}
 ```
</details>
<details><summary> LECTURE 10 : Linked list </summary>

**Linked list** is a data structure in computer programming, used to organize and store data. A linked list consists of a chain of "nodes", each containing a data value and a pointer to the next node in the chain.

Linked List ADT

- insert - adds an element at the beginning of the list

- delete - deletes an element at the beginning of the list

- deleteAt - remove the element using a given key

- size - return the number of elements in the list

- isEmpty - Return true if the list is empty, otherwise return false

- search - searches an element using a key


```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* self-referential structure */
struct node
{
    int value;
    struct node *next;
};

struct node* createNode(int);
void insertNodeAtTheBeginning();
void insertNodeAtTheEnd();
void insertNodeAtPosition();
void deletePosition();
void search();
void updateValue();
void display();

struct node *newnode, *ptr, *prev, *temp;
struct node *head = NULL, *tail = NULL;

int main() {
    int ch = '\0';

    while (true)
    {
        printf("\n---------------------------------\n");
        printf("\nOperations on a linked list\n");
        printf("\n---------------------------------\n");
        printf("\n1.Insert node at beginning");
        printf("\n2.Insert node at end");
        printf("\n3.Insert node at a specific position");
        printf("\n4.Delete Node from any Position");
        printf("\n5.Update Node Value");
        printf("\n6.Search Element in the linked list");
        printf("\n7.Display List");
        printf("\n8.Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
		case 1:
		    insertNodeAtTheBeginning();
		    break;
		case 2:
		    insertNodeAtTheEnd();
		    break;
		case 3:
		    insertNodeAtPosition();
		    break;
		case 4:
		    deletePosition();
		    break;
		case 5:
		    updateValue();
		    break;
		case 6:
		    search();
		    break;
		case 7:
		    display();
		    break;
		case 8:
		    printf("\n...Exiting...\n");
		    return 0;
		default:
		    printf("\n...Invalid Choice...\n");
		    break;
		}
    }
    return 0;
 }

/*
 * Creating Node
 */
struct node* createNode(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

void insertNodeAtTheBeginning()
{
    int val = 0;

    printf("\nEnter the value for the node: ");
    scanf("%d", &val);
    newnode = createNode(val);
    if (head== tail && head == NULL)
    {
        head = tail = newnode;
        head->next = NULL;
        tail->next = NULL;
    }
    else
    {
        temp = head;
        head = newnode;
        head->next = temp;
    }
}

void insertNodeAtTheEnd()
{
    int val = 0;

    printf("\nEnter the value for the Node: ");
    scanf("%d", &val);
    newnode = createNode(val);
    if (head == tail && tail == NULL)
    {
        head = tail = newnode;
        head->next = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = NULL;
    }

 printf("\n----INSERTED----");
}

void insertNodeAtPosition()
{
    int pos, val, cnt = 0, i;

    printf("\nEnter the value for the Node: ");
    scanf("%d", &val);
    newnode = createNode(val);
    printf("\nEnter the position ");
    scanf("%d", &pos);
    ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (pos == 1)
    {
        if (head == tail && head == NULL)
        {
            head = tail = newnode;
            head->next = NULL;
            tail->next = NULL;
        }
        else
        {
            temp = head;
            head = newnode;
            head->next = temp;
        }
        printf("\nInserted");
    }
    else if (pos>1 && pos<=cnt)
    {
        ptr = head;
        for (i = 1;i < pos;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
        printf("\n----INSERTED----");
    }
    else
    {
        printf("Position is out of range");
    }
}


void deletePosition()
{
    int pos, cnt = 0, i;

    if (head == NULL)
    {
        printf("List is empy\n");
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted: ");
        scanf(" %d", &pos);
        ptr = head;
        if (pos == 1)
        {
            head = ptr->next;
            printf("\nElement deleted");
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)
            {
                ptr = head;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range ");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }
}


void updateValue()
{
    int oldval, newval, flag = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        printf(":No nodes in the list to update\n");
    }
    else
    {
        printf("\nEnter the value to be updated: ");
        scanf("%d", &oldval);
        printf("\nEnter the new value:");
        scanf("%d", &newval);
        for (ptr = head;ptr != NULL;ptr = ptr->next)
        {
            if (ptr->value == oldval)
            {
                ptr->value = newval;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nUpdated Successfully");
        }
        else
        {
            printf("\nValue not found in List");
        }
    }
}

void search()
{
    int flag = 0, key, pos = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        printf(":No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search ");
        scanf("%d", &key);
        for (ptr = head;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for (ptr = head;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}
```

</details>
<details><summary> LECTURE 11 : Stack and Queue </summary>

# STACK

**Overview**

- a stack is a constrained version of a linked list

- all insertions and deletions are only made at the top of the stack

- the last item to be put in to the stack is always the first item to be removed

  - referred to as a last-in, first-out (LIFO) data structure
 
- a stack is referenced via a pointer to the top element of the stack

  - the link member in the last node of the stack is set to NULL to indicate the bottom of the stack

  - not setting the link in the bottom node of a stack to NULL can lead to runtime errors

- stacks and linked lists are represented identically

  - difference is that insertions and deletions may occur anywhere in a linked list, but only at the top of a stack

**Basic Operations**

- the primary functions used to manipulate a stack are the push and pop function

- push inserts a new element and places it on top of the stack

- pop removes an element from the top of the stack
   - frees the memory that was allocated and returns the element
- other operations include
  
   - peek - looking at an element at the top without removing it
     
   - isEmpty - checking if the stack is empty

**Illustration**
 

![image](https://github.com/phatminhswe/advancedC/assets/162662273/61048426-d2fa-4dfc-941d-b0a86caf5cc5)


**Applications**

- stacks support recursive function calls

  - whenever a call is made, the function must know how to return to its caller, so the return address is pushed onto a stack
  
  - if a series of function calls occurs, the successive return values are pushed onto the stack in last-in, first-out order so that each function can return to its caller

- stacks are used to store data in memory

  - contain the space created for automatic variables on each invocation of a function

  -when the function returns the space for those variables is popped off the stack
  
- the call stack is useful when debugging
  
  -shows each function call and any nested function calls
  
  -stacks are used by compilers in the process of evaluating expressions and generating machine language code
  
- balancing symbols (matching starting and ending brackets, parenthesis)

- stacks can be used when implementing page visited history in a web browser

- a stack could be used as an "undo" operation in a text editor

- a stack can be used to implement post-fix notation in a computer language ( order of operations and operands)

  - infix to Postfix/Prefix conversion

- used in many algorithms like Tower of Hanoi, tree traversals, stock span problem, histogram problem

- an application to reverse a string could use a stack

  - push each letter of the string on to the stack

  - then pop them back (string is now reversed)
 
**Implementation**

EX:

```c

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty( Stack stack) {
    return stack.top == -1;
}

int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    return 0;
}


```

# QUEUE

**Overview**

- another common data structure is the queue

- a queue is similar to a checkout line in a grocery store

  - the first person in line is serviced first

  - other customers enter the line only at the end and wait to be serviced

- queue elements are removed only from the head of the queue

- queue elements are inserted only at the tail of the queue

- a queue is referred to as a first-in, first-out (FIFO) data structure

- try not to confuse a queue with a stack

  - a stack works based on the last-in-first-out (LIFO) principle

  - the difference between stacks and queues is in removing

    - in a stack we remove the item that was most recently added

    - in a queue, we remove the item that was least recently added
- there are two main operations in a queue

  - enqueue

  - dequeue

- enqueue will insert an element into the back of the queue

- dequeue will remove an element from the front of the queue

- other operations

  - IsEmpty - check if queue is empty

  - IsFull - check if queue is full

  - peek - get the value of the front of queue without removing it

  - poll or offer (same as dequeue and enqueue)

**Illustration**
 
![image](https://github.com/phatminhswe/advancedC/assets/162662273/588aa26e-9d04-443d-9985-efe758adfc79)


**Applications**

EX:

```c

#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));

    return 0;
}

```










</details>















