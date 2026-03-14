#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

// 1.如何自己学会阅读 C 语言 API 文档。(发现我的电脑看b不了 C函数速查.chm 这个文件)
int main(){

    //看文档的思路
    //1.初学者不要copy
    //2.传入 &t &p 可直接传递NULL尝试

    //例子1：随机数
    //时间单位 给他才行
    srand((unsigned )time(NULL));

    int i = 0;
    for(i = 0; i < 10; i++){
        printf("随机数：%d\n", rand() % 100);
    }
    printf("hello world");

    //例子2：拷贝
    //定义个以数组
    char src[10] ;
    char *str = "hello world";
    //拷贝
    strcpy(src, str);
    printf("拷贝后的字符串：%s\n", src);

    //如果要成为c工程师 C函数速查.chm  大部份函数要过一遍


    return 0;
}