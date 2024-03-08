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
```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
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
```
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
```
#ifndef __ABC_H
#define __ABC_H

int a = 10;

#endif
```
```
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
```
#include <stdio.h>
#define STRINGIZE(x)
#define DATA 40
int main() {
// Sử dụng toán tử
printf("The value is: %s\n", STRINGIZE(DATA));
return 0;
}
```
```
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
```
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
```
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
```
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
```
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
```
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
```
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

```
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

```
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

# LECTURE 3 : POINTER

- Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số khái niệm cơ bản về con trỏ trong C:

![image](https://github.com/phatminhswe/advancedC/assets/162662273/35130344-62a1-45c2-baaf-1db96081131b)


- Cách khai báo:
```
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float

```
- Lấy địa chỉ của một biến và truy cập giá trị:
```
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
int y = *ptr_x;  // y sẽ bằng giá trị của x

```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch

```
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));
    return 0;
}

```
- Ứng dụng:

```
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

```
void *ptr_void;

```
```
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
```
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
```
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

```
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
```
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
```
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
```
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
```
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

# LECTURE 4 : Memory layout

**Memory layout**

-Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.


![image](https://github.com/phatminhswe/advancedC/assets/162662273/e03f680a-7462-401d-a3f5-6a25013a02c6)


**Text segment**

Mã máy:
- Chứa tập hợp các lệnh thực thi.
- Quyền truy cập: Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. 
- Lưu hằng số, con trỏ kiểu char.
- Tất cả các biến lưu ở phần vùng Text đều không thể thay đổi giá trị mà chỉ được đọc.
```
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
  #include <stdio.h>
```
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
```
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

```
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


```
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
```
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
```
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
  
```
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
















  

















