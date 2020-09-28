//給一個int a[10]已排序的陣列，請寫一個function(a, size, b)能依照參數b(b = 0~4)別印出該區間的數字，且不包含a陣列內的元素
//b = 0, 印出0~99//
//b = 1, 印出100~199
//...
#include <stdio.h>
#include <stdlib.h>

void print_no_duplicated(int*,int,int);
int main(){

    int a[10] = {4,9,11,43,45,55,61,92,99,270};
    print_no_duplicated(a,10,2);
}

void print_no_duplicated(int* input,int size,int b){

    int p_a=0;
    while(input[p_a]<b*100)
        p_a++;

    for(int i=b*100;i<(b+1)*100;i++){
        if(input[p_a]==i)
            p_a++;
        else
            printf("%i ",i);
    }
    printf("\n");
}
