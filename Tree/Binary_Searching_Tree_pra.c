#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    
    int data;
    struct TreeNode* left_t;
    struct TreeNode* right_t;
};

typedef struct TreeNode T_Node;

T_Node* CreateTree(int*,int);
T_Node* InsertNode(T_Node*,int);
void Inorder(T_Node*);
void Preorder(T_Node*);
void Postorder(T_Node*);
T_Node* deleteNode(T_Node*,int);
int empty(T_Node*);
int GetHeight(T_Node*);

int main(){
    
//    int data[9] = {1,4,3,2,6,5,7,8,9};
    int data[9] = {5,6,4,8,2,3,7,1,9};
    
    T_Node* root =NULL;
    root = CreateTree(data,9);

    printf("tree in order:");
    Inorder(root);
    printf("\n");

    printf("tree pre order:");
    Preorder(root);
    printf("\n");

    printf("tree post order:");
    Postorder(root);
    printf("\n");

    printf("tree height=%i\n",GetHeight(root));
    return 0;
}

T_Node* InsertNode(T_Node* root,int value){

    T_Node* cur=root;
    T_Node* pre_cur=NULL;
    T_Node* new_Node;

    new_Node = (T_Node*)malloc(sizeof(T_Node));
    new_Node->data = value;
    new_Node->right_t = NULL;
    new_Node->left_t  = NULL;

    if(cur==NULL)
        return new_Node;

    while(cur!=NULL){
        pre_cur = cur;
        if(value > cur->data)
            cur = cur->right_t;
        else 
            cur = cur->left_t;
    }

    if(value > pre_cur->data)
        pre_cur->right_t = new_Node;
    else
        pre_cur->left_t = new_Node;

    return root;
}

T_Node* CreateTree(int* nums,int numsSize){

    T_Node* root = NULL;
    for(int i=0;i<numsSize;i++)
        root = InsertNode(root,nums[i]);

    return root;

}

void Inorder(T_Node* root){

    if(root!=NULL){
        Inorder(root->left_t);

        if(root!=NULL)
            printf("%2i",root->data);

        Inorder(root->right_t);
    }
}

void Preorder(T_Node* root){
    if(root!=NULL){
        if(root!=NULL)
            printf("%2i",root->data);

        Preorder(root->left_t);
        Preorder(root->right_t);
    }
}

void Postorder(T_Node* root){
    if(root!=NULL){
        Postorder(root->left_t);
        Postorder(root->right_t);

        if(root!=NULL)
            printf("%2i",root->data);
    }
}

int empty(T_Node* root){

    if(root==NULL)
        return 1;
    return 0;
}

T_Node* deleteNode(T_Node* root,int value){

    if(root==NULL)
        return NULL;
    
    T_Node* cur = root;
    T_Node* pre_cur = NULL;
    while(cur->data !=value){
        pre_cur = cur;
        if(value > root->data)
            cur = cur->right_t;
        else
            cur = cur->left_t;

        if(cur==NULL){
            printf("Node want to delete not found");
            return root;
        }
    }

    if(cur->left_t ==NULL && cur->right_t == NULL){
        if(pre_cur==NULL)
            return NULL;
        
        if(pre_cur->right_t==cur)
            pre_cur->right_t = NULL;
        else 
            pre_cur->left_t = NULL;
    }
    else if(cur->left_t==NULL && cur->right_t!=NULL){
        if(pre_cur==NULL)
            return cur->right_t;
        
        if(pre_cur->right_t ==cur)
            pre_cur->right_t = cur->right_t;
        else 
            pre_cur->left_t = cur->right_t;   
    }
    else if(cur->left_t!=NULL && cur->right_t==NULL){
        if(pre_cur==NULL)
            return cur->left_t;
        
        if(pre_cur->right_t ==cur)
            pre_cur->right_t = cur->left_t;
        else 
            pre_cur->right_t = cur->right_t;
    
    }
    else if(cur->left_t!=NULL && cur->right_t!=NULL){
//尋找左樹最大或右樹最小來代替要刪除的點
        T_Node pre_head;
        pre_head.right_t = root;
        if(pre_cur==NULL)
            pre_cur = &pre_head;
    

//find left tree max 
        T_Node* pre_l_max=cur;
        T_Node* l_max=cur->left_t;
        while(l_max!=NULL){
            pre_l_max = l_max;
            l_max = l_max->right_t;
        }
        if(pre_cur->right_t==cur){
            pre_l_max->right_t = cur->right_t;
            pre_cur->right_t = pre_l_max;
        }
        else{
            pre_l_max->right_t = cur->right_t;
            pre_cur->left_t = pre_l_max;
        }

        return pre_head.right_t;
    }

    return root;
}

int GetHeight(T_Node* root){

    if(root==NULL)
        return 0;
    
        int h_r = GetHeight(root->right_t);
        int h_l = GetHeight(root->left_t);

        if(h_r<h_l)
            return(h_l+1);
        else
            return(h_r+1);
}
