#include <stdio.h>

//指针难度高点
int main(){
int number_int = 100;
double number_double = 200.0;
printf("number_int = %d\n", *(&number_int));//取值 取number_int的地址，然后取值 输出100
printf("number_double = %f\n", *(&number_double));//取值 取number_double的地址，然后取值 输出200.0


printf("hard===============\n");
// 加难度

int * int_ptr = &number_int;//int * 是int类型的指针  (指针永远存放的是内存地址)
double * double_ptr = &number_double;//double * 是double类型的指针  (指针永远存放的是内存地址)
printf("int_ptr = %d\n", *int_ptr);//取值 取int_ptr的地址，然后取值 输出100
printf("double_ptr = %f\n", *double_ptr);//取值 取double_ptr的地址，然后取值 输出200.0

    return 0;
}