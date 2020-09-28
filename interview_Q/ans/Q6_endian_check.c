#include <stdio.h>
#include <stdlib.h>

typedef union{
    unsigned long l;
    char c[2];  // 16 bits
}data_endian;
int main(void){
    
    data_endian check;

    check.l = 0x1234;

    if(check.c[0]==0x12&&check.c[1]==0x34){
        printf("big endian\n");
    }
    else if(check.c[0]==0x34&&check.c[1]==0x12){
        printf("Little endian\n");
    }
    else
        printf("unknown data endian\n");

    return 0;

}
