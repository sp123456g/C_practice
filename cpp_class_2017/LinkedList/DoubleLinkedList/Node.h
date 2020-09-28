#pragma once 
#include <iostream>
template<class T>
class CNode{
    public:
     T m_value;
     CNode<T>* m_After;
     CNode<T>* m_Before;

     CNode(){
        m_After = NULL;
        m_Before = NULL;
     }
     
     ~CNode(){
       
     }
};
