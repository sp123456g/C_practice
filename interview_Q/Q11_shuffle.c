//Q11 write a function to shuffle an array ramdomly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

void shuffle(int* input){

    srand(time(NULL));
    int tmp;
    for(int i=SIZE-1;i>0;i--){
        int idx = rand()%i;
        tmp = input[idx];
        input[idx] = input[i];
        input[i] = tmp;
    }
}
int main(){
    
    int array[] = {0,1,2,3,4,5,6,7,8,9,10};
    
    for(int i=0;i<SIZE;i++)
        printf("%i ",array[i]);

    printf("\n");
    
    shuffle(array);
    for(int i=0;i<SIZE;i++)
        printf("%i ",array[i]);
    printf("\n");

}
