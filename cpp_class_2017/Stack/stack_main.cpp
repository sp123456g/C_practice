#include "stack.h"


int main(){

CBaseStack<int> Stack;

unsigned int number;
unsigned int put_in_number;
unsigned int count;
std::cout<<"Enter the size:";
std::cin>>number;
Stack.SetSize(number);
std::cout<<"How many number do you want to put in:";
std::cin>>put_in_number;

for(int i=0;i<put_in_number;i++){
if(Stack.PushBack(i))
std::cout<<"Put in:"<<i<<std::endl;
else{
    std::cout<<"Out of bound!"<<std::endl;
}
}

std::cout<<"//////////////Insert 70 at index 2//////////////////"<<std::endl;
std::cout<<"////////// Remove index 5 ////////////////////"<<std::endl;
Stack.Remove(5);
Stack.Insert(2,70);
if(put_in_number<number)
   count=put_in_number;
else
    count = number;
for(int i=0;i<count;i++){
    std::cout<<"Pop:"<<Stack.pop()<<std::endl;
}
}
