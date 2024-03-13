#include <stdio.h>
#include <setjmp.h>
#include "string.h"
jmp_buf buf;
char *error_code;
int exception_value = 0;

#define TRY if((exception_value = setjmp(buf)) == 0)
#define CATCHALL else
#define CATCH(NUM) else if(exception_value == NUM)
#define THROW(NUM,error)  error_code = error;\
longjmp(buf, NUM)

 enum ErrorCodes { 
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR, 
    CALCULATION_ERROR 
};

void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    printf("Đang kết nối mạng...\n");
    THROW(NETWORK_ERROR, "Lỗi kết nối: Network không tồn tại.");
}

void calculateData() {
    printf("Đang tinh toán dữ liệu...\n");
   THROW(CALCULATION_ERROR, "Lỗi tính toán: Kết quả không tồn tại.");
}



int main(int argc, char const *argv[])
{


    TRY {
        readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR) {
        printf("%s\n", error_code);
    } CATCH(NETWORK_ERROR){
        printf("%s\n", error_code);
    } CATCH(CALCULATION_ERROR){
        printf("%s\n", error_code);
    }


}