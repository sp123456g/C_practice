#include "CircularDoubleLinedList.h"

int main(){

    CLinkedList<int> LL;
    
    for(int i=0;i<10;i++){
        LL.AddElement(i);
    }
    for(int i=50;i<53;i++)
        LL.AddElement_Front(i);

//    LL.InsertElement(8,40);
    LL.ShowElement();
  //  LL.Remove(5);
  //  LL.ShowElement();

return 0;
}
