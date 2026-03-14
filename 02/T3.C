#include <stdio.h>
//数组与数组指针
int main(){
    //定义数组
    int arr[] = {1,2,3,4};
    //遍历数组
    //其他平台不能用，linux上拨错
    // for(int i = 0; i < 3; i++){
    //     printf("arr[%d] = %d\n", i, arr[i]);
    // }
    //定义数组指针
   
    //linux、clion、mac上都可以
    int i = 0;
    //遍历数组指针
    for(int i = 0; i < 4; i++){
        //打印数组名或者数组名的地址，都是数组的首地址，也就是数组第一个元素的地址
        printf("arr[%d] = ", arr);
        printf("数组名的地址 = ", &arr);
        printf("arr[%d] = %d\n", i, &arr[i]);
    }

    //居然数组就是一个内存地址
    //取出数组名的地址，赋值给数组指针
    int *arrPtr = arr;
    printf("arrPtr = %d\n", arrPtr);

    //指针位移，指针的值会加1，加的是一个类型的大小
    arrPtr++;
    printf("arrPtr = %d\n", arrPtr);

    arrPtr+=2;
    printf("arrPtr = %d\n", arrPtr);

    //指针移动到数组第一个元素的地址
    arrPtr -=3;
    printf("arrPtr = %d\n", arrPtr);
 
    //三维数组 仅提到了概念，没有实际使用
    // int ***arrpp；
    return 0;
    
}