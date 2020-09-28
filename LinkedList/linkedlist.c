#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* ptr_next;
};
struct List{
    struct Node* head;
    int size;
};
void printlist(struct List*);
void deleteNode(struct List*,int);
void insert(struct List*,int,int);
void addFront(struct List*,int data);
void addBack(struct List*,int data);
int main(){
    struct Node* zero;
    struct Node* one;
    struct Node* two;
    struct Node* thr;
    struct Node* head;

    struct List* a_list;

    a_list = (struct List*)malloc(sizeof(struct List));
    zero = (struct Node*)malloc(sizeof(struct Node));
    one = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    thr = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));
   
    zero->value = 10;
    zero->ptr_next = one;
    one->value = 11;
    one->ptr_next = two;
    two->value = 12;
    two->ptr_next = thr;
    thr->value = 13;
    thr->ptr_next = NULL;

    a_list->head = zero;

    printlist(a_list);
    deleteNode(a_list,3);
    printf("\nAfter delete index 3:\n");
    printlist(a_list);
    insert(a_list,1,50);
    printf("\nAfter insert index 1 as 50:\n");
    printlist(a_list);
    addBack(a_list,50);
    printf("\nAfter addBack 50:\n");
    printlist(a_list);
    addFront(a_list,1000);
    printf("\nAfter addFront 1000:\n");
    printlist(a_list);
    return 0;
}

void printlist(struct List* input){

    struct Node* curr = input->head;
    while(curr!=NULL){
        printf("%p->%i:",curr,curr->value);
        curr = curr->ptr_next;
    }
    printf("NULL\n");
}

void deleteNode(struct List* input,int position){
    
    if(position ==0){
        input->head=input->head->ptr_next;
        return;
    }
    struct Node* i=input->head; 
    for(int j=0;j<position-1;j++){
        i=i->ptr_next;
    }
    i->ptr_next = i->ptr_next->ptr_next;
}

void addFront(struct List* input,int data){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->value = data;
    newNode->ptr_next = input->head;
    input->head = newNode;
}
void addBack(struct List* input,int data){
    
    struct Node* curr = input->head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));

    while(curr->ptr_next!=NULL)
        curr = curr->ptr_next;
    
    newNode->ptr_next = NULL;
    curr->ptr_next = newNode;
    newNode->value = data;
}

void insert(struct List* input,int position,int data){
    
    struct Node *curr = input->head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    if(position==0){
        addFront(input,data);
        return;
    }
    for(int i=0;i<position-1;i++)
        curr = curr->ptr_next;

    newNode->value = data;
    newNode->ptr_next = curr->ptr_next;
    curr->ptr_next = newNode;
}
