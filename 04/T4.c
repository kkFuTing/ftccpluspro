# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//4.字符串的转换，字符串的比较

//真正的c语言，在Linux上学，在VIM上才是专业的
int main(){
    //1.字符串的转换
    char * num = "1";
    num = "12.68";
    int numInt = atoi(num);
    if(numInt){ //如果numInt不为0，则转换成功
        printf("恭喜你转换成功 numInt = %d\n", numInt);
    }else{
        printf("转换失败 numInt = 0\n");
    }

    double numDouble = atof(num);
    if(numDouble){ //如果numDouble不为0，则转换成功
        printf("恭喜你转换成功 numDouble = %f\n", numDouble);
    }else{
        printf("转换失败 numDouble = 0\n");
    }
    

    printf("\n字符串的比较\n");
    //2.字符串的比较
    char *str1 = "Hello";
    char *str2 = "hello";
    if(strcmp(str1, str2) == 0){ //0 相等 1非0 不相等  strcmp区分大小写
        printf("两个字符串相等\n");
    }else{
        printf("两个字符串不相等\n");
    }

    
    //不区分大小写的比较
    if(strcmpi(str1, str2) == 0){
        printf("两个字符串相等\n");
    }else{
        printf("两个字符串不相等\n");
    }
    return 0;


}