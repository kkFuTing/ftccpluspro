#include <stdio.h>

int main(){
    int arrInt[] = {6,4,8,3,1,2,9,7,0,5};
    int result = arrInt[*arrInt+*(arrInt+4)];
    //*arrInt 取值为7
    //*(arrInt+4) 取值为5
    //*arrInt+*(arrInt+4) 取值为12
    //arrInt[12] 取值为12
    printf("result = %d\n", result);
    return 0;
    
}