#pragma once 
#include <iostream>
template<class T>
class CNode{
    public:
     T m_value;
     CNode<T>* m_PointerToNext;

     CNode(){
        m_PointerToNext = NULL;
     }
     
     ~CNode(){
       
     }
};
