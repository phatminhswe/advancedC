#include <stdio.h>
#include <setjmp.h>
#include "string.h"
#include <float.h>
jmp_buf buf;
char *error_code;
int exception_value = 0;

#define TRY if((exception_value = setjmp(buf)) == 0)
#define CATCHALL else
#define CATCH(NUM) else if(exception_value == NUM)
#define THROW(NUM,error)  error_code = error;\
longjmp(buf, NUM)


double divide(int a, int b) {
   if (b == 0) {
       THROW(1, "Lỗi: Phép chia cho 0!"); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   if ((a == DBL_MAX && b == 1) || (a == DBL_MIN && b == -1)) {
        THROW(2, "Lỗi: Tràn số!");
    }
   return (double)a / b;
}



int main(int argc, char const *argv[])
{
double result;
TRY{

result = divide(10,0);
printf("Divide = %lf\n", result);

}CATCH(1){
  printf("%s\n", error_code);
}
CATCHALL{
  printf("%s\n", error_code);
}
return 0;
}