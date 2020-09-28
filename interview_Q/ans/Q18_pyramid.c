/*please print:
 *
 *    999999999
 *     7777777
 *      55555
 *       333
 *        1
 * */
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
    
    int top = 9;
    
    for(int i=top;i>0;i-=2){
        for(int j=0;j<(top-i)/2;j++)
            printf(" ");
        for(int j=0;j<i;j++)
            printf("%i",i);
        printf("\n");
    }
}
