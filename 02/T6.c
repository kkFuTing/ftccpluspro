#include <stdio.h>
//5.数组指针操作的几种方式
int main(){
    int arr[] = {1,3,5,7};
    int *arrPtr = arr;
    for(int i = 0; i < 4; i++){

        printf("arr[%d] = %d\n", i, arr[i]);
        printf("arrPtr[%d] = %d\n", i, arrPtr[i]);
        printf("*(arrPtr + %d) = %d\n", i, *(arrPtr + i));
        printf("*(%d + arrPtr) = %d\n", i, *arrPtr+i);//这个是错误的，因为arrPtr是数组指针，不能直接加i
        printf("\n");
    }
    return 0;
}