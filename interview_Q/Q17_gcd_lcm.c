//Q17: write a function find out gcd and lcm
#include <stdio.h>
#include <stdlib.h>

void calculate(int a,int b,int* gcd,int* lcm){

    int aa = a,bb=b;
    
    if(a<b){
        aa = b;
        bb = a;
    }
    int re;
    while(aa%bb!=0){
        re = aa%bb;
        aa = bb;
        bb = re;
    }
    *gcd = bb;
    *lcm = a*b/(*gcd);
}

int main(){


    int a=30,b=45;

        int gcd=0;
        int lcm=0;
        calculate(a,b,&gcd,&lcm);

    printf("GCD=%i,LCM=%i\n",gcd,lcm);

}
