# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// 5.字符串查找，包含，拼接
int main(){
    //1.字符串查找
    char *str = "name is Futing";
    char *findStr = "F";
    char *find = strstr(str, findStr);
    if(find){
        printf("找到 %s 了\n", findStr);
    }else{
        printf("没有找到 %s 了\n", findStr);
    }
    //怎么去字符串查找
    int index1 = strcspn(str, findStr);
    printf("index1 = %d\n", index1);

    //包含了吗
    if(strstr(str, findStr)){
        printf("包含 %s\n", findStr);
    }else{
        printf("不包含 %s\n", findStr);
    }

    //求位置
    int index = find - str;
    printf("index = %d\n", index);

    //指针是可以 ++ -- += -= 的
    find++;
    printf("find = %s\n", find);
    find--;
    printf("find = %s\n", find);
    find += 2;
    printf("find = %s\n", find);
    find -= 2;
    printf("find = %s\n", find);

    //拼接
    char destination[25];
    char * blank ="--到--",*CPP="C++",*JAVA="Java";
    strcpy(destination, CPP);//先拷贝CPP到destination数组
    strcat(destination, blank);//再拼接blank到destination数组
    strcat(destination, JAVA);//再拼接JAVA到destination数组
    printf("destination = %s\n", destination);

    return 0;
}