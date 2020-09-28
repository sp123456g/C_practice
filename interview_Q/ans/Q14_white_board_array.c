#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){



    int size = 100;
    int output[size/4][4];

    for(int i=1;i<=size;i+=4){
        int mode = (int)(floor(i/4))%3;
        if(mode==0){
            for(int j=0;j<4;j++)
                output[(int)floor(i/4)][j] = j+i;
        }
        else{
            int row_x,col_begin;
            if(mode==1){
                row_x     = floor(i/4);
                col_begin = 0;
            }
            else{
                row_x     = floor(i/4)-1;
                col_begin = 2;
            }
            output[row_x][col_begin]   = i;
            output[row_x+1][col_begin] = i+1;
            output[row_x+1][col_begin+1] = i+2;
            output[row_x][col_begin+1]   = i+3;
        }
    }

    for(int i=0;i<size/4;i++){
        for(int j=0;j<4;j++)
            printf("%3i ",output[i][j]);

        printf("\n");
    }
}
