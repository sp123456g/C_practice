//Q22: strcat:  combine two string to one string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strcat1(char*,char*);
int main(){

    char s1[] = "Hi!";
    char s2[] = " I'm Yen-Hsiang\n";
   
    char* s3 = strcat(s1,s2); 
    printf("%s",s3);
}

char* strcat1(char* str1,char* str2)
{
    int l_1 = strlen(str1);
    int l_2 = strlen(str2);
    int size = l_1+l_2;
    char* out = malloc(sizeof(char)*size);

    for(int i=0;i<l_1;i++)
        out[i] = str1[i];
    for(int i=0;i<l_2;i++)
        out[i] = str2[i];

    return out;
}
