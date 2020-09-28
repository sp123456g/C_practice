#include <stdlib.h>
#include <stdio.h>

struct tree{
    int val;
    struct tree* left;
    struct tree* right;
};

typedef struct tree treenode;

treenode* create_btree(int*,int);
treenode* insert_node(treenode*,int);
//create BST 
treenode* create_btree(int* nums,int numsSize){
    
    treenode* root = NULL;  //root pointer

    for(int i=0;i<numsSize;i++)
        root = insert_node(root,nums[i]);
    return root;
}
//insert BST node
treenode* insert_node(treenode* root,int value){
    
    treenode* newnode;
    treenode* current;
    treenode* back;          //father node
    
    newnode = (treenode*)malloc(sizeof(treenode));
    newnode->val = value;
    newnode->left =NULL;
    newnode->right=NULL;

    if(root ==NULL)
        return newnode;
    else{
        current = root;
        while(current !=NULL){
            back = current;
            if(value <= current->val)
                current = current->left;
            else
                current = current->right;
        }
        if(value <= back->val)
            back->left = newnode;
        else 
            back->right = newnode;
    }

    return root;
}

void Postorder(treenode* root) {   //後序追蹤 Left Right Root
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);

        if(root!=NULL)
            printf("%i ",root->val);
    }
}

void Inorder(treenode* root) {  //中序追蹤  Left Root Right

    if(root!=NULL){
        Inorder(root->left);
        if(root!=NULL)
            printf("%i ",root->val);
        Inorder(root->right);
    }
}

void Preorder(treenode* root) {  //前序追蹤  Root Left Right
    if(root!=NULL){
        if(root!=NULL)
            printf("%i ",root->val);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main(){
    treenode* root = NULL;

    int data[9] ={5,6,4,8,2,3,7,1,9};
    root = create_btree(data,9);

    printf("tree inorder:\n");
    Inorder(root);
    printf("\n");

    printf("tree postorder:\n");
    Postorder(root);
    printf("\n");

    printf("tree preorder:\n");
    Preorder(root);
    printf("\n");


    return 0;
}
