#include <stdio.h>
//互换两个变量的值
//只接收指针（内存地址），不接收变量；内存地址 == 指针
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 100;
    int b = 200;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
