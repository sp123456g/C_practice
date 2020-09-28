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

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
