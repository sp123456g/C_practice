#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
unsigned int test (unsigned int x)
{
    while(x&(x-1)!=0)
        x = x&(x-1);
    return x;
}

int get_highest_bit_order(unsigned x){
    int n = 31;
    if(x == 0) return -1;
    if((x>>16) == 0) { n = n - 16; x = x << 16;}
    if((x>>24) == 0) { n = n -  8; x = x <<  8;}
    if((x>>28) == 0) { n = n -  4; x = x <<  4;}
    if((x>>30) == 0) { n = n -  2; x = x <<  2;}
    if((x>>31) == 0) { n = n -  1;}
    return n;
}

int least_significant_bit_1(int x)
{

    for(int i=0;i<31;i++){
     if(x & 1<<i)
        return i;   
    }
}

bool isPalindrome(char * s){

    int p_e = strlen(s)-1;
    int p_f = 0;

    if(strlen(s)==0)
        return true;



    while(p_f<strlen(s)){

        if (s[p_f] >= 'A' && s[p_f] <= 'Z')
            s[p_f]+=32;
        if(s[p_e] >= 'A' && s[p_e] <= 'Z')
         s[p_e]+=32;

        if(s[p_f] < 'a' || s[p_f] > 'z'){
            p_f++;
            continue;
        }

        if(s[p_e] < 'a' || s[p_e] > 'z'){
            p_e--;
            continue;
        }

        if(s[p_f] != s[p_e])
            return false;
        else{
            if(p_e>0 && p_f<strlen(s)){
                p_f++;
                p_e--;
            }
            else
                return true;
        }
    }
    return true;
}

int main(){

    char s[] = "0P";
    int len = strlen(s);
    unsigned int a=24;
    int out = test(a);
    int out2 = get_highest_bit_order(a);
    int out3 = least_significant_bit_1(a);
    printf("ANS=%i\n",out);
    printf("highest_bit=%i\n",out2);
    printf("least_significant_bit of %i is=%i\n",a,out3);
    printf("-a=%i\n",~a+1);
    printf("strlen(Hello)=%i\n",len);
    printf("yes or no:%i\n",isPalindrome(s));

}
