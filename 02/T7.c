#include <stdio.h>
//6.指针类型有啥用
int main(){
    int num = 100;
    int *numPtr = &num;
    //强制类型转换 规范上是不行的 ，检测无法通过
    // double *num2Ptrd = numPtr;

    //指针占用的内存大小是？ 4个字节
    printf("numPtr = %d\n", sizeof numPtr);

    double num3 = 10.0;
    double * num3Ptrd = &num3;  // 取 num3 的地址赋给指针
    printf("num3Ptrd = %d\n", sizeof num3Ptrd);

    //6.指针类型有啥用?既然都是四个字节，那么分指针类型有什么用？
    //答：取值的时候怎么取，这是类型规定的好处 （int类型取值的时候，取4个字节，double类型取值的时候，取8个字节）
    printf("num = %d\n", num);
    printf("numPtr = %d\n", numPtr);
    return 0;
}