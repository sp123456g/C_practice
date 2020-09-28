//Q4: Write a function strcmp() to check if two string is the same or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcmp_yhh(char*,char*);
int main(){

    char s1[7] = "Hello!";
    char s2[9] = "Hello!!";

    if(strcmp_yhh(s1,s2))
        printf("The same\n");
    else
        printf("not the same\n");
}

int strcmp_yhh(char* str1,char* str2){

    int i=0;
    while(str1[i]!='\0' && str1[i]!='\0'){
        if(str1[i]!=str2[i])
            return 0;

        i++;
    }

    if(str1[i]!=str2[i])
        return 0;
    
    return 1;
}
