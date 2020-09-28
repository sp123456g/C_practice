#include <stdio.h>
#include <stdlib.h>

int main(){

    for(int i=1;i<=5;i++){
        for(int j=0;j<5-i;j++)
            printf(" ");
        for(int j=0;j<i;j++)
            printf("*");
        printf("\n");
    }
}
