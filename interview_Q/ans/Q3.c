#include <stdio.h>
#include <stdlib.h>


struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define null 0xffff
unsigned int ListHead = 0;

int main(){

}
//ListArray[Entry].DataH == Data_A 且 ListArray[Entry].DataL == Data_B
//*條件一：ListArray[Entry1].NextPtr = ListArray[Entry2]
//*條件二：ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL > ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL

void found_entry(unsigned int DATA_A, unsigned int DATA_B){

    unsigned int p_pre=null;
    unsigned int p_now=ListHead;
    int found = 0;

    while(ListArray[p_now].NextPtr!=null){
        if(ListArray[p_now].DataH==DATA_A && ListArray[p_now].DataL==DATA_B){
            if(p_pre==null)
                printf("found entry1==null,entry2==head");
            else
                printf("found_entry1==%i,entry2==%i",p_pre,p_now);

            if(ListArray[p_now].DataH << 16 + ListArray[p_now].DataL > ListArray[p_pre].DataH << 16 + ListArray[p_pre].DataL){
                found = 1;
                break;
            }
        }
        else{
            p_pre = p_now;
            p_now = ListArray[p_now].NextPtr;
        }
    }

    if(!found)
        printf("no found");
}
