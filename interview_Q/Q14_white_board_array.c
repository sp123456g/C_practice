//Q14: print array:
//  1   2   3   4
//  5   8   9  12
//  6   7  10  11
// 13  14  15  16
// 17  20  21  24
// 18  19  22  23





#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){



    int size = 24;
    int output[size/4][4];
//start here    

    int mode,row,col;
    for(int i=1;i<=size;i+=4){
        mode = (int)(i/4)%3;
        row = floor(i/4);
        if(mode==0){
            for(int j=0;j<4;j++)
                output[row][j] = i+j;
        }
        else{
            col = 0;
            if(mode==2){
                col = 2;
                row -=1;
            }
            output[row][col] = i;
            output[row+1][col] = i+1;
            output[row+1][col+1] = i+2;
            output[row][col+1] = i+3;

        }
    }
//end
    for(int i=0;i<size/4;i++){
        for(int j=0;j<4;j++)
            printf("%3i ",output[i][j]);

        printf("\n");
    }
}
