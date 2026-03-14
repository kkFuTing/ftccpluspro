#include <stdio.h>

void callBackMethod(char *fileName, int currrent,int total){
    printf("文件名：%s\n", fileName);
    printf("当前进度：%d\n", currrent);
    printf("总进度：%d\n", total);
}

//压缩方法
//定义函数指针：返回值（*名称）（int，double）
void compress(char *fileName, void (*callBackMethodPtr)(char *, int, int)){
    callBackMethodPtr(fileName, 10, 100);
}

int main(){
    //写法一：
    //vs clion 通过了，linux不通过
    void(*call1)(char *, int, int) = callBackMethod;
    compress("test.txt", call1);

    //写法二：
    printf("\nlinux通过\n");
    //linux通过
    void(*call)(char *, int, int) ;
    call = callBackMethod;
    compress("test.txt", call);
    return 0;
}