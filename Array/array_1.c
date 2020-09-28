#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int array[24];
    for(int i=1;i<=24;i++)
        array[i-1] = i;

    for(int i=0;i<24;i++)
        printf("%i ",array[i]);
    printf("\n");

    int array_out[6][4];
    int mode;
    
    for(int i=0;i<24;i+=4){
        mode = (int)(floor(array[i]/4))%3;
        int row = floor(array[i]/4);
        if(mode ==0){
           for(int j=0;j<4;j++)
              array_out[row][j] = array[i+j]; 
        }
        else if(mode==1){
            array_out[row][0]   = array[i];
            array_out[row+1][0] = array[i+1];
            array_out[row+1][1] = array[i+2];
            array_out[row][1]   = array[i+3];
        }

        else if(mode==2){
            array_out[row-1][2]   = array[i];
            array_out[row][2] = array[i+1];
            array_out[row][3] = array[i+2];
            array_out[row-1][3]   = array[i+3];
        }
    }


    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++)
            printf("%3i",array_out[i][j]);
        printf("\n");
    }
}
