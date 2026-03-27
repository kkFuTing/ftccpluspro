#include <stdio.h>

int main(){
    int arrInt[] = {6,4,8,3,1,2,9,7,0,5};
    printf("arrInt = %d\n", arrInt);
    int result = arrInt[*(arrInt+*(arrInt+4))];
    // arrInt 是 0
    
    printf("result = %d\n", result);
    return 0;
    
}