#include <stdio.h>//c99 标准库引入头文件

//java 万物皆对象
//c c++ 万物借指针
int main(){


    int a = 10;

    //%p 是打印地址的占位符
    //&a 是取a变量的地址
    printf("此a变量的地址是%p\n", &a);

    int *p = &a;
    printf("a = %d, p = %p\n", a, p);
    printf("*p = %d\n", *p);
    printf("&a = %p\n", &a);
    printf("&p = %p\n", &p);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    printf("&a = %p\n", &a);

    return 0;
}