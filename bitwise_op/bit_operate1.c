#include <stdio.h>
#include <stdlib.h>

unsigned getBits(unsigned x,int p,int n);
int main(){
    
    int a= 100;
    printf("after get:%d\n",getBits(a,0,4));
}

unsigned getBits(unsigned x, int p, int n)
{
 return ( x >> (p-n) ) & ~( ~0 << n );
 /* 取出 x 的第 p 位置起 n 個 bits */
}
