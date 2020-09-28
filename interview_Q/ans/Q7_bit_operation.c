#include <stdio.h>
#include <stdlib.h>

int change_bit(int,int,int);
int main(){

    int a=6;
    int out = change_bit(a,5,1);  //ans=38
    printf("ans=%i\n",out);
}

int change_bit(int input,int position,int value){

   int mask = 1<<position;

  return((input & ~mask)|(value<<position)); 

}
