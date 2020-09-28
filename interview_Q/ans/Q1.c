//Q1: 給一個int a[10]已排序的陣列，請寫一個function(a, size)能印出0~100的數字，且不包含a陣列內的元素，請用最少的時間和空間複雜度完成。
#include <stdio.h>
#include <stdlib.h>

void print_no_duplicated(int*);
int main(){

    int a[10] = {2,4,9,11,43,45,55,61,92,99};
    print_no_duplicated(a);
}

void print_no_duplicated(int* input){

    int p_a=0;
    for(int i=0;i<=100;i++){
        if(input[p_a]==i)
            p_a++;
        else
            printf("%i ",i);
    }
    printf("\n");
}
