//Q13: check if the number is power of two 
#include <stdio.h>
#include <stdlib.h>

int check_pow_two(int input){

    return((input&(input-1))==0);
};
int main(){

    int a;
    printf("Enter number:");
    scanf("%i",&a);
    
//    for(int i=0;i<50;i++){
        if(check_pow_two(a))
            printf("%i is power of two\n",a);
        else 
            printf("%i is not power of two\n",a);
  //  }

}
