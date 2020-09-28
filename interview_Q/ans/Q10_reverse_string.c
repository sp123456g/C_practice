#include <stdio.h>
#include <stdlib.h>

void string_reverse(char* str1){

//check size 
    int p_b=0;
    while(str1[p_b]!='\0')
        p_b++;

    p_b--;

    int p_f = 0;

    int temp;
    while(p_f<p_b){
        temp = str1[p_f];
        str1[p_f] = str1[p_b];
        str1[p_b] = temp;
        p_f++;
        p_b--;
    }
}
int main(){

    char str[] = "FrAnk";
    printf("str=%s\n",str);
    string_reverse(str);
    printf("str=%s\n",str);
}
