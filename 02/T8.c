#include <stdio.h>
void add(int a, int b){
    printf("a + b = %d\n", (a+b));
}
void minus(int a, int b){
    printf("a - b = %d\n", (a-b));
}

//操作回调到 add minus 函数
//void (*func)(int, int) 这个是函数指针，func 是函数名，(int, int) 是函数参数，void 是函数返回值
void operate(int a, int b, void (*func)(int, int)){
    func(a, b);
    printf("func指针是：%p\n", func);
}

//7.指针函数
int main(){
    operate(10, 20, add);
    operate(10, 20, minus);

    printf("mian函数的add指针是：%p\n", add);
    printf("mian函数的minus指针是：%p\n", minus);

    //取地址符 & 取的是函数的地址
    printf("mian函数的&add：%p\n", &add);
    printf("mian函数的&minus：%p\n", &minus);
    return 0;
}