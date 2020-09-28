//Q3: 
//ListArray[Entry].DataH == Data_A 且 ListArray[Entry].DataL == Data_B
//*條件一：ListArray[Entry1].NextPtr = ListArray[Entry2]
//*條件二：ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL > ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL


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
void found_entry(unsigned int DATA_A, unsigned int DATA_B){

    unsigned int p_pre = null;
    unsigned int p_now = ListHead;
    
    while(p_now!=null){
        if(ListArray[p_now].DataH==DATA_A && ListArray[p_now].DataL==DATA_B){
            if(p_now==ListHead)
                printf("Entry2 = %i,Entry1=NULL\n",p_now);
            else{
                if(ListArray[p_now].DataH << 16 + ListArray[p_now].DataL > ListArray[p_pre].DataH << 16+ListArray[p_pre].DataL){
                    printf("Entry2=%i,Entry1=%i",p_now,p_pre);
                }
            }
        }
        else{
            p_pre = p_now;
            p_now = ListArray[p_now].NextPtr;
        }
    }
}
