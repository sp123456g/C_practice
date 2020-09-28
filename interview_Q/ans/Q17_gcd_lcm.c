#include <stdio.h>
#include <stdlib.h>

void calculate(int a,int b,int* gcd,int* lcm){

    int aa=a;
    int bb=b;
    if(aa<bb){
        aa = b;
        bb = a;
    }

    int re;
    while(bb!=0){
        *gcd = bb;
        re = aa%bb;
        aa = bb;
        bb = re;
    }
    *lcm = a*b/(*gcd);
}

int main(){


    int a=30,b=45;

        int gcd=0;
        int lcm=0;
        calculate(a,b,&gcd,&lcm);

    printf("GCD=%i,LCM=%i\n",gcd,lcm);

}
