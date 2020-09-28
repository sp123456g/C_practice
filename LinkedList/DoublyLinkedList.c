#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* p_next;
    struct Node* p_pre;
};

struct DLList{
    struct Node* head;
    struct Node* tail;
};
void printf_DDL(struct DLList);
void addFront(struct DLList*,int value);
void addBack(struct DLList*,int value);
void Insert_front(struct DLList*,int position,int value);
void Insert_Back(struct DLList*,int position,int value);

int main(){

    struct Node list[5];
    
    for(int i=0;i<5;i++){
        list[i].data = i*10;
    }
    
    for(int i=0;i<4;i++)
        list[i].p_next = &(list[i+1]);
        list[4].p_next = NULL;
    for(int i=1;i<5;i++)
        list[i].p_pre = &(list[i-1]);
        list[0].p_pre = NULL;


    struct DLList list_a;
    list_a.head = list;
    list_a.tail = &list[4];



    printf("Original:\n");
    printf_DDL(list_a);

    addFront(&list_a,500);
    printf("addFront 500:\n");
    printf_DDL(list_a);




    addBack(&list_a,400);
    printf("addBack 400:\n");
    printf_DDL(list_a);

    Insert_Back(&list_a,2,654);
    printf("Insert_Back 654 at index 2:\n");
    printf_DDL(list_a);



    Insert_front(&list_a,4,777);
    printf("Insert_front 777 at index 4\n");
    printf_DDL(list_a);
    
}

void printf_DDL(struct DLList input_ddl){

    struct Node* cur = input_ddl.head;
//    while(cur!=NULL){
//        printf("%p<-%d->%p--",cur->p_pre,cur->data,cur->p_next);
//        cur = cur->p_next;
//    }
//    printf("NULL\n");
    cur = input_ddl.head;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur = cur->p_next;
    }
    printf("\n");
}

void addFront(struct DLList* in_list,int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
    new_node->p_pre = NULL;
    new_node->p_next = in_list->head;
    new_node->data = value;
    in_list->head->p_pre = new_node;
    in_list->head = new_node;
}

void addBack(struct DLList* in_list,int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
    new_node->data = value;
    new_node->p_pre = in_list->tail;
    new_node->p_next = NULL;
    in_list->tail->p_next = new_node;
    in_list->tail = new_node;
}

void Insert_front(struct DLList* in_list,int position,int value){
   if(position==0){
    addFront(in_list,value); 
    return;
   }
   struct Node* curr = in_list->head;
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
   for(int i=0;i<position-1;i++)
       curr = curr->p_next;
   new_node->data   = value;
   new_node->p_next = curr->p_next;
   new_node->p_pre  = curr;
   curr->p_next->p_pre = new_node;
   curr->p_next = new_node;
}

void Insert_Back(struct DLList* in_list,int position,int value){
    
    Insert_front(in_list,position+1,value);
}
