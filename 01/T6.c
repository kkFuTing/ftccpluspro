#include <stdio.h>
//通过指针（地址）修改值
int main(){

    int a = 100;
    int *p = &a; //指针p指向a的地址
    a = 100;
    printf("a = %d\n", a);//输出100
  
    *p = 300; //通过指针p修改a的值  *p 是取指针p指向的地址的值，修改为300
    printf("a = %d\n", a);//输出300
    return 0;
}