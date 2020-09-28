#include "queue.h"


int main(){
    unsigned int size;
    unsigned int number_of_element; 
    CBaseQueue<int> Queue;
    
    std::cout<<"Enter the size of the queue:";
    std::cin>>size;
    std::cout<<"How many element do you want to put in:";
    std::cin>>number_of_element;
    
    Queue.SetSize(size);
    
    for(int i=0;i<number_of_element;i++){
        Queue.PushBack(i);
        std::cout<<"PushBack: "<<i<<std::endl;
    }
    Queue.Insert(5,60);
    for(int i=0;i<number_of_element+1;i++){
        std::cout<<"Pop: "<<Queue.Pop()<<std::endl;
    
    }

}
