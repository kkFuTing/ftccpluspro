#include <iostream>
//<>是系统库
//""是自定义库
# include "fuc.h"
using namespace std;

void (*funcp)();
void ponit_fuc(){
    printf("函数指针\n");
}

int* int_add_func(void* wParam){
    printf("指针函数");
    int b = 10;
    int *p = &b;
    // getchar();//暂停 可以阻塞程序
    return p;
}


int main()
{
    cout << "hello worldcccccccc";
    func();
    int a = 10;
    int_add_func(&a);

    funcp = ponit_fuc; //赋值的过程不会调用
    printf("赋值的过程不会调用\n");
    funcp();//调用的时候才会打印

}

//如果要写在调用之后，需要定义头函数
int func(void)
{
    printf("函数");
    return -1;
}

int func(void *pathnum, int a)
{
}