/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){

    struct ListNode* p_fast = head;
    struct ListNode* p_slow = head;
    struct ListNode* p_mid  = NULL;
    if(p_fast==NULL || p_fast->next ==NULL)
        return true;
// find middle
    while(p_fast!=NULL && p_fast->next!=NULL){
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
    }
    
    if(p_fast==NULL)
        p_mid = p_slow;
    else
        p_mid = p_slow->next;
    
//reverse second half    
    struct ListNode* p_next=NULL;
    struct ListNode* p_pre=NULL;
    while(p_mid!=NULL){
        p_next = p_mid->next;
        p_mid->next = p_pre;
        p_pre = p_mid;
        p_mid = p_next;
    }

    while(p_pre!=NULL){
        if(p_pre->val !=head->val)
            return false;
        p_pre = p_pre->next;
        head = head->next;
    }
    return true;
}
