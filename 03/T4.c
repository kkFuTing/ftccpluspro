#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void dynamicAction(){
    int *p；//野指针，没地址，空的
    //VOID * 可以指向任何类型的数据 int* double* char*
    int * arr = malloc(1*1024*1024);//堆区开辟4MB
    //如果不释放，每次地址都不一样，
    //dynamicAction函数，arr自己的内存地址 = 000000000061FDE8.堆区开辟的内存地 
    //如果加上释放，每次的内存地址一样
    printf("dynamicAction函数，arr自己的内存地址 = %p.堆区开辟的内存地址 = %p\n", &arr, arr);
    free(arr); //释放内存 
    printf（"释放后地址还存在 %p",arr）
    arr = NULL; //重新指向内存地址为00000
}
//molloc 在堆区开辟的内存空间。（动态的范畴）
int main(){
    while(9){
        // sleep(100);
        dynamicAction();
    }

    return 0;
    
}