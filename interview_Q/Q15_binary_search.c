//Q15: Implement binary search
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int Binary_search(int* input,int target){

    int L = 0;
    int R = SIZE-1;
    int M;
    while(L<=R){
        M = L + (int)(R-L)/2;
        if(target==input[M])
            return M;
        else if(target<input[M])
            R = M-1;
        else 
            L = M+1;
    }

    return -1;
}
int main(){
    int array[SIZE] = {1,2,3,4,5,45,67,89,99,101};
    int target;

    printf("Enter target:");
    scanf("%i",&target);

    int idx = Binary_search(array,target);
    printf("Target %i is at index %i\n",target,idx);
    
}
