#include <stdio.h>
#include <stdlib.h>



int main(){
    // 0111 and 0110 = 0110
    // 0110 and 0101 = 0100
    // 0100 and 0011 = 0000
    int a = 19;
    int count = 0;
    while(a != 0){
        a = a & (a - 1);
        count += 1;
    }
    printf("%d\n",count);
    return 0;
}
