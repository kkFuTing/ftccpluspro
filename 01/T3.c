#include <stdio.h>
//基本类型占用的字节数（常用的）
int main(){

    printf("int 数据类型索占的字节数：%d\n",sizeof(int));
    printf("double 数据类型索占的字节数：%d\n",sizeof(double));
    printf("float 数据类型索占的字节数：%d\n",sizeof(float));
    printf("long 数据类型索占的字节数：%d\n",sizeof(long));
    printf("short 数据类型索占的字节数：%d\n",sizeof(short));
    printf("char 数据类型索占的字节数：%d\n",sizeof(char));

    return NULL;
}