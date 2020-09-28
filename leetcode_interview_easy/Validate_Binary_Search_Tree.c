/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode*,long,long);
bool isValidBST(struct TreeNode* root){
    
    return(helper(root,LONG_MIN,LONG_MAX));
}

bool helper(struct TreeNode* root,long min,long max){
    
    if(root==NULL)
        return true;
    
    bool L = helper(root->left,min,root->val);
    bool R = helper(root->right,root->val,max);
    
    if(L && R){
        if(root->val<=min || root->val>=max)
            return false;
        else
            return true;
    }
    else
        return false;
    
}
