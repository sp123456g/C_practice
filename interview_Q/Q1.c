//Q1: 給一個int a[10]已排序的陣列，請寫一個function(a, size)能印出0~100的數字，且不包含a陣列內的元素，請用最少的時間和空間複雜度完成。
#include <stdio.h>
#include <stdlib.h>

void print_no_duplicated(int*);
int main(){

    int a[10] = {2,4,9,11,43,45,55,56,57,58};
    print_no_duplicated(a);
}

void print_no_duplicated(int* x){

    int p_x = 0;
    for(int i=0;i<=100;i++){
        if(p_x!=10){
            if(i==x[p_x])
                p_x++;
            else
                printf("%i ",i);
        }
        else{
            for(int j=i;j<=100;j++)
                printf("%i ",j);
            break;
        }
    }
    printf("\n");
}
