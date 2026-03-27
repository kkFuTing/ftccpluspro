
// # include <stdio.h>
// //3.指针挪动获取字符串信息（手写API）
// int getLen(char *str){
//     int len = 0;
//     while(*str != '\0'){
//         len++;
//         str++;
//     }
//     return len;
// }

// int main(){
//     char str[] = {'A','B','C','D','\0'};
//     //获取字符串长度,手写API
//     printf("len = %d\n", getLen(str));
//     return 0;
// }



# include <stdio.h>
//C/C++ 编译器 数组作为参数传递，会把数组优化成指针 （为了高效）
int getLenErr(int  intArr[]){
    //不能这么写了
    int len = sizeof(intArr) / sizeof(int);
    printf("getLen = %d\n", len);
    return len;
}


void getLen(int *resultLen, int  intArr[]){
//手动计算长度
int count = 0;
while(*intArr != '\0'){
    intArr++;
    count++;
}
*resultLen = count;
}
int main(){
    int arrInt[] = {1,2,3,0,5,6,7,'\0'};//0 和 '\0' 都是结束符 会冲突 这个会在int类型冲突
    方式1：使用sizeof
    int len = sizeof(arrInt) / sizeof(int);
    //获取字符串长度,手写API
    printf("len = %d\n", len);
    getLenErr(arrInt);

    int resultLen = 0;//& 取出resultLen的地址，然后传递给getLen函数
    getLen(&resultLen, arrInt);
    printf("resultLen = %d\n", resultLen);
    return 0;
}