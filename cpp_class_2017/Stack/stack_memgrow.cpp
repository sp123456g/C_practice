#include "stack_memgrow.h"


int main(){
    CStack<int> stack;
    std::cout<<"PushBack:"<<std::endl;
    for(int i=0;i<=50;i++){
    
          stack.PushBack(i);
          std::cout<<i<<"\t";
    }
std::cout<<std::endl<<"//////////////// pop out ///////////////"<<std::endl;
    for(int i=0;i<=50;i++){
    
        std::cout<<stack.Pop()<<"\t";
    }
    std::cout<<std::endl;
}
