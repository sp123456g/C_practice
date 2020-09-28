#include <stdio.h>
#include <stdlib.h>

int strcmp_yhh(char*,char*);
int main(){

    char s1[7] = "Hello!";
    char s2[9] = "Hello!ff";

    if(strcmp_yhh(s1,s2))
        printf("The same\n");
    else
        printf("not the same\n");
}

int strcmp_yhh(char* str1,char* str2){

    int p_1=0;
    int p_2=0;

    while(str1[p_1]!='\0'||str2[p_2]!='\0'){
        if(str1[p_1]==str2[p_2]){
            p_1++;
            p_2++;
        }
        else 
            return 0;
    }

    return 1;
}
