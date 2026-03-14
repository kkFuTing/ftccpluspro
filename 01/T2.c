#include <stdio.h>

int main(){

    int i = 10;
    double d = 100.0;
    float f = 100.0;
    long l = 100;
    short s = 100;
    char c = 'A';
    // bool b = true;
    //注意c的输出要占位符
    //d = 整形
    printf("i = %d, d = %f, f = %f, l = %ld, s = %d, c = %c\n", i, d, f, l, s, c);
}