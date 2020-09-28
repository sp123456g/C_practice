#include "Node.h"

template<class T>

class CLinkedList{

    private:
        CNode<T>* m_Head;
        CNode<T>* m_Tail;
    public:
//Constructor       
        CLinkedList(){
            m_Head =NULL;
            m_Tail =NULL;
        };
//Destructor
        ~CLinkedList(){
           CNode<T>* now = m_Head;
        //   CNode<T>* now2 = m_Tail;
          while(now!=NULL){
              CNode<T>* temp = now->m_After;
          //    CNode<T>* temp2 = now->m_Before;
                 delete now;
              //   delete now2;
                 now = temp;
               //  now2 = temp2;
          }
        };
//Show the element of linkedlist
        void ShowElement(){
            CNode<T>* now = m_Head;
            while(now!=NULL){
             std::cout<<"<--"<<now->m_Before<<"  "<<now->m_value<<"  "<<now->m_After<<"-->"<<std::endl;
                now = now->m_After;
            }
        };
//Add element behind
        bool AddElement(T value){
            if(m_Head==NULL && m_Tail==NULL){
                m_Head = new CNode<T>;
                m_Head->m_value = value;
                m_Head->m_Before = m_Head;
                m_Head->m_After = m_Head;
                m_Tail = m_Head; 
                return true;
            }
            else {
                m_Tail->m_After = new CNode<T>;
                m_Tail->m_After->m_value = value;
                m_Tail->m_After->m_Before = m_Tail;
                m_Tail = m_Tail->m_After; 
                m_Tail->m_After= m_Head;
                m_Head->m_Before = m_Tail->m_After;
            }
        };
//Add element Front        
        bool AddElement_Front(T value){
            CNode<T>* now;
            if(m_Head==NULL){
                now = new CNode<T>;
                m_Head = now;
                m_Tail = now;
                now->m_value = value;
                now->m_After = now;
                now->m_Before = now;
            }
            else{
                now = new CNode<T>;
                now->m_After = m_Head;
                m_Head = now;
                now->m_value = value;
                now->m_After->m_Before = now;
                now->m_After->m_After = m_Head;
                m_Head->m_Before = now->m_After;
            }
            return true;
        };        
//Insert element at the position
     //   bool InsertElement(int position,T value){
    //        CNode<T>* now;
     //       if(m_Head==NULL){
      //          now= new CNode<T>;
        //        m_Head = now;
          //      m_Head->m_value = value;
            //    return true;
           // }
            //if(position==0)
              //      AddElement_Front(value);
            //else{
                //now=m_Head;
                  //  for(int i=0;i<position-1;++i){
                //        now = now->m_PointerToNext;    
              //    }
            //
              //  CNode<T>* PointerToInsertion;
            //    PointerToInsertion = new CNode<T>;
          //      PointerToInsertion->m_PointerToNext = now->m_PointerToNext;
        //        PointerToInsertion->m_value = value;
      //          now->m_PointerToNext = PointerToInsertion;
    //            return true;
  //          }
//        };
//Remove element of the list
      //  void Remove(int position){
         //   CNode<T>* now;
          //  if(m_Head==NULL)
           //     return;
          //  if(position==0){
           //     m_Head = m_Head->m_PointerToNext;
          //      return;
          //  }
            //    now=m_Head;
        //    for(int i=0;i<position-1;i++){
      //          now = now->m_PointerToNext;
    //        }

  //           now->m_PointerToNext = now->m_PointerToNext->m_PointerToNext;
//
  //              
//            return;
//        };
};
