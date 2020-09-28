#include <iostream>


template <class T>
class CBaseStack {

    private:
         T* Element;
         unsigned int m_End;
         unsigned int m_Size;
                  T*  m_Element;
    public:
         CBaseStack(){
            m_End  = 0;
            m_Size = 0;            
            m_Element =NULL;
         };

         ~CBaseStack(){
            delete[] m_Element;
         };
         
         bool SetSize(int size){
             if(m_Element!=NULL)
                 delete[] m_Element;
             m_Size =size;
             m_Element = new T[m_Size];
             return true; 
         };

         bool PushBack(T value){
            if(m_End!=0 && m_End==m_Size){
              //BC check
                return false;
            }
            else{
             if(m_Element==NULL){
             m_Element[0]= value;
             m_End=1;
             return true;
             }
             else {
             
             m_Element[m_End]=value;
             m_End++;
             return true;
             };
            }
         };
         T pop(){
           if(m_Element==NULL) 
               return 0;
           else    
               --m_End;
               return m_Element[m_End];
                 
         };

        bool Insert(int position,T value){
    
         if(m_End==m_Size &&m_End!=0)
             return false;
         else {  
             for(int i=m_End;i>position;i--){
                m_Element[i]=m_Element[i-1];
             }
                m_Element[position]= value;
                m_End++;
                return true;
         }
        };
         bool Remove(int position){

             for(int i=position;i<m_End;i++){
                
                m_Element[i]=m_Element[i+1];
            }
                m_End--;
                return true;
         };  
        };        
