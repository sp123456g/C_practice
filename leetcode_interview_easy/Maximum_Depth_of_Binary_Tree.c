/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    
    if(root==NULL)
        return 0;
    
    int D_l = maxDepth(root->left);
    int D_r = maxDepth(root->right);
    
    if(D_l>D_r)
        return D_l+1;
    else 
        return D_r+1;
}
