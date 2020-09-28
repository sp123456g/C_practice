//Q12: Calculate how many bits in the specific binary number

#include <stdio.h>
#include <stdlib.h>



int calBits(int input);
int main(){
    int a=1023;
    int out = calBits(a);

    printf("output=%i\n",out);
    return 0;
}

int calBits(int input){
    int count = 0;

    while(input!=0){
        input = input &(input-1);
        count++;
    }
    return count;
}
