//print array:
//  1   2   3   4   5
//  16  17  18  19  6
//  15  24  25  20  7
//  14  23  22  21  8
//  13  12  11  10  9
         
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int size = 25;
    int input[size];
    int length = sqrt(size);
    int output[length][length];
    for(int i=0;i<size;i++)
        input[i] = i+1;

    for(int i=0;i<size;i++)
        printf("%i ",input[i]);
    printf("\n");

        int row_b=0;
        int row_e=length-1;
        int col_b=0;
        int col_e=length-1;
    for(int i=0;;){
        for(int j=col_b;j<=col_e;j++)
            output[row_b][j] = input[i++];
        row_b++;
        if(i==size)
            break;
        for(int j=row_b;j<=row_e;j++)
            output[j][col_e] = input[i++];
        col_e--;
        if(i==size)
            break;
        for(int j=col_e;j>=col_b;j--)
            output[row_e][j] = input[i++];
        row_e--;
        if(i==size)
            break;
        for(int j=row_e;j>=row_b;j--)
            output[j][col_b] = input[i++];
        col_b++;
        if(i==size)
            break;
    }

    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            printf("%4i",output[i][j]);
        }
        printf("\n");
    }
}
