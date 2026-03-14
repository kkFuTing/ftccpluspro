#include <stdio.h>
//4.循环时给数组赋值
int main(){
    //定义数组
    int arr[4];
    int *arrPtr = arr;

    //循环时给数组赋值
    int i = 0;
    //没有length
    for(int i = 0; i < 4; i++){
    // for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        //1.拿到元素1，元素2，元素3，元素4的内存地址，*（arrPtr + i）
        //2.给内存地址赋值，*(arrPtr + i) = i + 1;
        *(arrPtr + i) = i + 10001;
    }

    //把j定义在循环外，才是规范的
    int j = 0;
    //循环时打印数组
    for(int j = 0; j < 4; j++){
        printf("arr[%d] = %d\n", j, arr[j]);
    }


    return 0;
}