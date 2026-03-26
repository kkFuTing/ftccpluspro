#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//动态开辟的使用场景
int main(){
    //静态开辟的内存空间大小，是不能修改的，如果不需要动态修改空间大小，当然使用栈区
    //int arr [6];

    //下面是动态开辟的内存
    //开辟的空间， 想要变化，动态范畴
    int num;
    printf("请输入数的个数：");
    //获取用户输入的值
    scanf("%d", &num);
    //动态开辟用户输入的值 空间的大小 【堆区】
    int *arr= malloc(num * sizeof(int));
    // int []  //和int *arr 都是数组，只是 int *arr 可以使用指针

    int print_num;
    //循环接收
    int i = 0;
    for(int i =0 ;i <num ;++i){
     printf("请输入第%d个数：", i+1);    
     scanf("%d",&print_num);

     arr[i] =  print_num;
     printf("每个元素的值:%d,每个元素的的地:%p\n",*(arr+i),arr+i);
    }
    
    for(int i =0;i <num;++i){
        printf("输出元素结果是%d\n",arr[i]); //arr[i 隐士等价于 *（arr+i)
    
    }



    getchar();
}