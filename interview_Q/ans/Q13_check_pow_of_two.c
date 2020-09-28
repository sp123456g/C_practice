#include <stdio.h>
#include <stdlib.h>

int check_pow_two(int input){

    if(input!=1){
        if(input%2!=0)
            return 0;
        else{
            if(!(check_pow_two(input/2)))
                return 0;
            else 
                return 1;
        }
    }
    if(input==1)
        return 1;
    else 
        return 0;

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
