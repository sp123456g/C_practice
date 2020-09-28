#include <stdio.h>
#include <stdlib.h>

long F(int n){

    if(n<=2)
        return 1;
    else
        return F(n-1)+F(n-2);
}

long F2(int n){
    
    int a1=1,a2=1i,a3=0;   
    if(n<=2)
        return 1;
    else{
        for(int i=2;i<n;i++){
            a3=a1+a2;
            a1=a2;
            a2=a3;
        }
        return a3;
    }

}

int main(void){

    int a;
    printf("which index value you want to know:");
    scanf("%i",&a);

    printf("index=%i,value=%lo\n",a,F(a));

}
