#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

    int data;
    struct Node* p_next;

}node;

typedef struct CLL_list{
    node* head;
    node* tail;
}cll_list;

void push_front(cll_list**,int);
void push_back(cll_list**,int);
void insert_front(cll_list**,unsigned int,int);
void insert_back(cll_list**,unsigned int,int);
void print_cll(cll_list);

int main(void){

    cll_list* list_a;
    list_a->head =NULL;
    list_a->tail =NULL;
    push_back(&list_a,20);
    push_back(&list_a,40);
    push_back(&list_a,60);
    push_back(&list_a,80);

    push_front(&list_a,200);
    push_front(&list_a,400);
    push_front(&list_a,600);
    print_cll(*list_a);

    insert_front(&list_a,2,10000);
    print_cll(*list_a);

    insert_back(&list_a,4,10000);
    print_cll(*list_a);
}

void push_front(cll_list** in_list,int value){

    node* new_node = (node*)malloc(sizeof(node*));
    new_node->data = value; 
    if((*in_list)->head==NULL){
        new_node->p_next = new_node; 
        (*in_list)->head = new_node;
        (*in_list)->tail = new_node;
    }
    else{
        new_node->p_next = (*in_list)->head;
        (*in_list)->tail->p_next = new_node;
        (*in_list)->head = new_node;
    }
    return;
}

void push_back(cll_list** in_list,int value){

    node* new_node = (node*)malloc(sizeof(node*));
    new_node->data = value; 
    if((*in_list)->head==NULL){
        new_node->p_next = new_node; 
        (*in_list)->head = new_node;
        (*in_list)->tail = new_node;
    }
    else{
        new_node->p_next = (*in_list)->head;
        (*in_list)->tail->p_next = new_node;
        (*in_list)->tail = new_node;
    }
    return;
        
    
}
void insert_front(cll_list** in_list,unsigned int position,int value){

    if((*in_list)->head ==NULL)
        push_front(in_list,value);
    else if(position==0)
        push_front(in_list,value);
    else {
        node* cur = (*in_list)->head;
        node* new_node = (node*)malloc(sizeof(node*));
        new_node->data = value;
        for(int i=0;i<position-1;i++)
            cur = cur->p_next;

        new_node->p_next = cur->p_next; 
        cur->p_next = new_node;
    }
    return;
}

void insert_back(cll_list** in_list, unsigned int position,int value){

    if((*in_list)->head ==NULL)
        push_front(in_list,value);
    else if(position==0)
        push_front(in_list,value);
    else {
        node* cur = (*in_list)->head;
        node* new_node = (node*)malloc(sizeof(node*));
        new_node->data = value;
        for(int i=0;i<position;i++)
            cur = cur->p_next;

        new_node->p_next = cur->p_next; 
        cur->p_next = new_node;
    }
    return;

}

void print_cll(cll_list in_list){

    if(in_list.head ==NULL){
        printf("empty list\n");
        return;
    }
    
    node* head = in_list.head;
    node* tail = in_list.tail;
    while(head!=tail){
    
        printf("%i->",head->data);
        head = head->p_next;
    }
    printf("%i-~->",tail->data);
    printf("%i\n",tail->p_next->data);
    return;
}
