//Q22: print:
/*

* 
**
***
****
*****
******
*******
********
*********
**********

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int line,number=1;
    printf("Enter a number of line:");
    scanf("%i",&line);
    for(int i=0;i<line;i++){
        for(int j=0;j<number;j++)
            printf("*"); 
        number++;
        printf("\n");
    }

    return 0;

}
