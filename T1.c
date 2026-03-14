#include <stdio.h>

void add(int a, int b){
    printf("a + b = %d\n", a+b);
}

void testFunc(void (*func)(int, int)){
    printf("func = %p\n", func);

    //思考 为什么可以不用写*  函数的上面已经声明了func指针，所以可以不用写*
    (func)(10, 20);、
    (*func)(10, 20);

}
//上节课内容的一个点 函数指针
int main(){
    testFunc(add);
    return 0;
}