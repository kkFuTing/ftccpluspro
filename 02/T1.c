#include <stdio.h>

void upadte(int *i){
    //再取一次i的内存地址，就和main函数中的i的内存地址不一样了
    printf("update函数，i的内存地址是：%p\n", &i);
}

int main(){
    int i = 100;
    upadte(&i);
    printf("main函数，i的内存地址是：%p\n", &i);
    return 0;
}

