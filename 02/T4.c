#include <stdio.h>
//采用指针遍历数组
int main(){
    int arr[] = {1,2,3,4};
    int *arrPtr = arr;
    int i = 0;
    //数组是连续内存地址。每次移动4个字节，也就是一个int类型的大小
    for(int i = 0; i < 4; i++){
        printf("arr[%d] = %d\n", i, *(arrPtr + i));
        printf("arrPtr[%d] = %d\n", i, (arrPtr + i));
    }
    return 0;
}