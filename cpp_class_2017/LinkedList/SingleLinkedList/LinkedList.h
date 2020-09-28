#include "Node.h"

template<class T>

class CLinkedList{

    private:
        CNode<T>* m_Head;
    public:
//Constructor       
        CLinkedList(){
            m_Head =NULL;
        };
//Destructor
        ~CLinkedList(){
           CNode<T>* now = m_Head;
        
          while(now!=NULL){
              CNode<T>* temp = now->m_PointerToNext;
                 delete now;
                 now = temp;
          }
        };
//Show the element of linkedlist
        void ShowElement(){
            CNode<T>* now = m_Head;
            std::cout<<m_Head->m_PointerToNext<<"-->";
            while(now!=NULL){
                std::cout<<now->m_value<<":"<<now->m_PointerToNext<<"-->";
                now = now->m_PointerToNext;
            }
            std::cout<<std::endl;
        }
//Add element behind
        bool AddElement(T value){
          CNode<T>* now;
            if(m_Head==NULL){
                m_Head = new CNode<T>;
                now = m_Head;
            }
            else{
                now = m_Head;
                while(now->m_PointerToNext!=NULL)
                { now = now->m_PointerToNext; }
                
                now->m_PointerToNext = new CNode<T>;
                now = now->m_PointerToNext; 
            }

            if(now==NULL)
                return false;
            
            now->m_value = value;
            return true;
        };
//Add element Front        
        bool AddElement_Front(T value){
            CNode<T>* now;
            if(m_Head==NULL){
                now = new CNode<T>;
                m_Head = now;
            }
            else{
                now = new CNode<T>;
                now->m_PointerToNext = m_Head;
                m_Head = now;
            }
            if(now==NULL)
                return false;

             now->m_value = value;
            return true;
        };        
//Insert element at the position
        bool InsertElement(int position,T value){
            CNode<T>* now;
            if(m_Head==NULL){
                now= new CNode<T>;
                m_Head = now;
                m_Head->m_value = value;
                return true;
            }
            if(position==0)
                    AddElement_Front(value);
            else{
                now=m_Head;
                    for(int i=0;i<position-1;++i){
                        now = now->m_PointerToNext;    
                  }
            
                CNode<T>* PointerToInsertion;
                PointerToInsertion = new CNode<T>;
                PointerToInsertion->m_PointerToNext = now->m_PointerToNext;
                PointerToInsertion->m_value = value;
                now->m_PointerToNext = PointerToInsertion;
                return true;
            }
        };
//Remove element of the list
        void Remove(int position){
            CNode<T>* now;
            if(m_Head==NULL)
                return;
            if(position==0){
                m_Head = m_Head->m_PointerToNext;
                return;
            }
                now=m_Head;
            for(int i=0;i<position-1;i++){
                now = now->m_PointerToNext;
            }

             now->m_PointerToNext = now->m_PointerToNext->m_PointerToNext;

                
            return;
        };
};
