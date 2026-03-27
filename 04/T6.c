# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//指针的理解
void toLower(char *dest, char *name){
//临时指针，不能破坏name
    char *tempName = name;  

    while(*tempName != '\0'){
        //把一个个字符转换为小写
        *dest = tolower(*tempName);
        dest++; //挪动指针位置
        tempName++;//挪动指针位置
    }
    *dest = '\0'; //最后添加结束符，避免打印系统乱码
}

//6.大小转换（手写API）
int main(){
    //1.大小转换
    char *str = "name is Futing";
    //先定义结果
    char result[25];

    toLower(result, str);
    printf("小写转换的结果是：%s\n", result);

    return 0;
}