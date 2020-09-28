//Write a function to reverse string 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_reverse(char* str1){
    
    int p_r=strlen(str1)-1;
    int p_l=0;
    char tmp;
    while(p_l<p_r){
        tmp = str1[p_l];
        str1[p_l] = str1[p_r];
        str1[p_r] = tmp;
        p_l++;
        p_r--;
    }
}

int main(){

    char str[] = "FroAnk";
    printf("str=%s\n",str);
    string_reverse(str);
    printf("str=%s\n",str);
}
