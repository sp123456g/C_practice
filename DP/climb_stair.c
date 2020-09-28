#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){

    int out;
    if(n>2 && n<=45){
        out=climbStairs(n-1)+climbStairs(n-2);
       return out;
    }
    if(n==2)
        return 2;
    if(n==1)
        return 1;
    
    return 0;
}

int main(){

    int in;
    printf("Enter how many step you want to climb:");
    scanf("%i",&in);
    printf("%i steps has %i methods\n",in,climbStairs(in));
}
