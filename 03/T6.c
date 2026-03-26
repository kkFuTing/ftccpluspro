#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//动态开辟 realloc
int main(){

    int num;
    printf("请输入数的个数：");
    //获取用户输入的值
    scanf("%d", &num);

    //假设5个值
    int *arr= malloc(num * sizeof(int));

    int print_num;
    //循环接收
    int i = 0;
    for(int i =0 ;i <num ;++i){
    //  printf("请输入第%d个数：", i+1);    
    //  scanf("%d",&print_num);

     arr[i] =  (i + 10001); //arr[i] 的内部ying ==*
    //  printf("每个元素的值:%d,每个元素的的地:%p\n",*(arr+i),arr+i);
    }
    
    printf("arr的地址是(开辟的内存地址)%p\n",arr);

    for(int i =0;i <num;++i){
        //&取出内存地址然后*取值，&取出内存地址，然后*取值，直到取到值 ,*&*&*&*&*&*(arr+i)
        printf("开辟内存的指针的值是%d，内存地址是%p\n",*&*&*&*&*&*(arr+i),(arr+i));
    }

    //=====在堆区开辟新的空间，加长空间大小
    //新增
    int new_num;
    printf("请输入新增的数的个数：");
    scanf("%d", &new_num);
    //在堆区开辟新的空间，加长空间大小
    int *new_arr = realloc(arr, (new_num + num) * sizeof(int));
    if(new_arr == NULL){
        printf("内存分配失败\n");
        return -1;
    }

    int j = num;
    for(;j <new_num+num;++j){
        // printf("请输入第%d个数：", j+1);
        // scanf("%d", &print_num);
        new_arr[j] = (j + 10001);
        printf("开辟内存的指针的值是%d，内存地址是%p",*&*&*&*&*&*(new_arr+j),(new_arr+j));
    }
    arr = new_arr;
    printf("新增后的内存地址是%p\n",arr);
    //打印
    for(int i =0;i <new_num+num;++i){
        printf("新开辟内存的指针的值是%d，内存地址是%p\n",*(new_arr+i),(new_arr+i));
    }



    if(new_arr != NULL){
        free(new_arr);
        new_arr = NULL;
        arr = NULL; //他还在指向那块空间，为了不出现悬空指针，所以也要置空，指向NULL的空间
    }else{
        free(arr);
        arr = NULL;
        printf("内存释放失败\n");
    }

    printf("内存释放成功\n");
    getchar();//这是什么意思？这是等待用户输入，然后回车，然后程序继续执行
    return 0;
}