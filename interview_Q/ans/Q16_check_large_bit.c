#include <stdio.h>
#include <stdlib.h>



int checkLargeBits(int input);
int main(){
    int a=1024;
    int out = checkLargeBits(a);

    printf("output=%i\n",out);
    return 0;
}

int checkLargeBits(int x){
    int n=31;
    if(x>>16==0){n-=16;x=x<<16;}
    if(x>>24==0){n-=8;x=x<<8;}
    if(x>>28==0){n-=4;x=x<<4;}
    if(x>>30==0){n-=2;x=x<<2;}
    if(x>>31==0){n-=1;}

    return n;
    
}
