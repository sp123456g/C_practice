#pragma once 
#include <iostream>

template <class T>
class CBaseQueue{

    private:
        unsigned int m_Size;
        unsigned int m_Head;
        unsigned int m_Tail;
        unsigned int m_RealNum;
        T* m_Element;
    public:
     CBaseQueue(){
        
        m_Size = 0;
        m_Head = 0;
        m_Tail = 0;
        m_Element = NULL;
     };

     ~CBaseQueue(){
        delete[] m_Element;
     };
     
     void SetSize(int size){
            delete[] m_Element;
            m_Size =size;
            m_Element = new T[m_Size];
     };
     
     void PushBack(T value){
      if(m_Tail+1>m_Size){
          std::cout<<"out of bound"<<std::endl;
      }
      else{
        m_Element[m_Tail]= value;
        m_Tail++;
        m_RealNum++;
      }
      };
     
     T Pop(){
    
         if(m_RealNum==0)
             return 0;
         else{
             m_RealNum--;
            return m_Element[m_Head++];
            
         };
     };

     void Insert(unsigned int position,T value){
     
     for(int i=m_Tail;i>position;i--){
        m_Element[i]=m_Element[i-1];
     }
        m_Element[position] = value;
        m_Tail++;
        m_RealNum++;
     };
};
