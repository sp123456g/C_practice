#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

void shuffle(int* input){

    srand(time(NULL));
    
    int p;
    int get;
    int temp;
    for(int p=SIZE-1;p>0;p--){
        get = rand()%p;
        temp = input[p];
        input[p] = input[get];
        input[get] = temp;
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
