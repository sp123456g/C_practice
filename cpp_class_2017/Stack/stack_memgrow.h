#include <iostream>
#include <string.h>
template <class T>
class CStack {
    private:
        unsigned int m_MaxSize;
        unsigned int m_Num;
        unsigned int m_End;
        T* m_elements;
    public:
        CStack(){
            m_MaxSize  = 0;
            m_Num      = 0;
            m_End      = 0;
            m_elements = NULL;
        };

        ~CStack(){
            delete[] m_elements;
        };

        bool PushBack(T value){
            if(m_MaxSize==0){
                m_MaxSize =20;

                m_elements = new T[20];
            }
            if(m_Num<m_MaxSize){
                m_elements[m_End] = value;
                m_End++;
                m_Num++;
                return true;
            }
            else if(m_Num==m_MaxSize && m_Num!=0){
                T* temp_elements;
                temp_elements = new T[m_MaxSize+20];
                memcpy(temp_elements,m_elements,sizeof(T)*m_MaxSize);
                delete[] m_elements;
                m_elements = temp_elements;         
                m_elements[m_End] = value;
                m_End++;
                m_Num++;
                m_MaxSize+=20;
                return true;
            }
        };

        T Pop(){
            m_Num--;
            return m_elements[--m_End];
        };
};
