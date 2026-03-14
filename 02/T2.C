#include <stdio.h>
//多级指针
//指针是存放内存地址，但是本身也有内存地址
int main(){
    int num = 999;
    //一级指针 *
    //二级指针 **
    //三级指针 ***
    //在真实开发过程中，最多三级指针，如果需要更多，则需要使用其他数据结构来存储
    int *numPtr = &num; //取出num的内存地址，赋值给numPtr（一级指针）
    int **numPtrPtr = &numPtr; //取出numPtr的内存地址，赋值给numPtrPtr（二级指针）
    int ***numPtrPtrPtr = &numPtrPtr; //取出numPtrPtr的内存地址，赋值给numPtrPtrPtr（三级指针）
    printf("num的内存地址是：%p\n", &num);
    printf("numPtr的内存地址是：%p\n", numPtr);
    printf("numPtrPtr的内存地址是：%p\n", numPtrPtr);
    printf("numPtrPtrPtr的内存地址是：%p\n", numPtrPtrPtr);

    //先输出999
    printf("num的值是：%d\n", num);
    //再输出999
    printf("numPtr的值是：%d\n", *numPtr);
    //再输出999
    printf("numPtrPtr的值是：%d\n", **numPtrPtr);
    //再输出999
    printf("numPtrPtrPtr的值是：%d\n", ***numPtrPtrPtr);
    return 0;
}