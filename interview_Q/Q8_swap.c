//Q8: write swap(x,y) to change x value to y value,y value to x value
#include <stdio.h>
#include <stdlib.h>

void swap(int*,int*);
int main(){

    int a = 10;
    int b = 200;

    printf("a=%i,b=%i\n",a,b);
    swap(&a,&b);
    printf("a=%i,b=%i\n",a,b);
}

void swap(int* a,int* b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}
