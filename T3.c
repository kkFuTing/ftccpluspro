#include <stdio.h>

//函数进栈 定义一个int arr[5] ；定义一个 int i ；（静态的范畴）

//进栈
void startcAtion(){
    int arr[5];//静态开辟 栈区

    for(int i = 0; i < 5; i++){
        arr[i] = i;
        printf("arr[%d] = %d\n", *(arr+i), arr+i);
    }
    printf("startcAtion\n");
}//执行完毕出栈



// 2.静态开辟。
//涉及栈区内存开辟，堆区内存开辟，全局区内存开辟
int main(){
    //int 占4个字节 如果开辟10M的内存，会导致栈区内存不足，导致栈溢出报错的
    // int arr[10*1024*1024]; //10M*4字节=40M 如果开辟10M的内存，会导致栈区内存不足，导致栈溢出
    // int arr[1*1024*1024];  // 1*1024*1024*4字节=4M 会溢出，我log倒是没有报错内容，但是printf没有打印
    int arr[(int)(0.2*1024*1024)]; //0.2M*4字节=0.8M //会打印地址 不会栈溢出
    //栈区：占用内存最大值：大概 2M 根平台有关，如果超过2M，会栈溢出
    //堆区：占用内存最大值：大概80% 根平台有关，如果超过8M，会堆溢出
    // int arr[10] = {0};
    printf("arr的地址是：%p\n", arr);


    while(1){
        //无限循环也不会溢出，因为每次执行startcAtion函数，都会进栈，执行完毕后出栈，所以不会溢出
        startcAtion();
    }
    return 0;
}

// //C 中的布尔
// PS C:\Users\ting.fu\c++project\ftccpluspro> D:\tool\mingw64\bin\gcc.exe T3.c -o T3.exe; .\T3.exe
// 0是false
// 1是true
// -1是true
// 10是true
// int main(){
  
//     //非0就是true，0就是false

//     if(0){
//         printf("0是true\n");
//     }else{
//         printf("0是false\n");
//     }

//     if(1){
//         printf("1是true\n");
//     }else{
//         printf("1是false\n");
//     }

//     if(-1){
//         printf("-1是true\n");
//     }else{
//         printf("-1是false\n");
//     }

//     if(10){
//         printf("10是true\n");
//     }else{
//         printf("10是false\n");
//     }
//     return 0;
// }
