#include <stdio.h>
//函数 取修改一个数（指针操作）

//函数要写在main函数之前，因为要先定义函数，才能在main函数中调用
void change_int(int i); //先声明函数，//再实现函数，就不会报错


int main(){
    int a = 100;
    change_int(a);
    printf("==============================\n");
    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    return 0;
}

void change_int(int i){ //C/C++ 编译器 构建形参 是一个新的，既然是新的，那么修改形参，不会影响实参，内存地址不一样，无法修改实参
    printf("value = %p\n", &i);
    printf("i = %d\n", i);
    i = 200; 
}