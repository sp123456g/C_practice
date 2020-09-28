struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode preHead;
    struct ListNode* p_last;
    preHead.val  = 1000;
    p_last = &preHead;
    
    while(l1!=NULL && l2!=NULL){
        
        
        if(l1->val<=l2->val){
            p_last->next = l1;
            l1 = l1->next;
            p_last = p_last->next;
        }
        else{
            p_last->next = l2;
            l2=l2->next;
            p_last = p_last->next;
        }
    }
    
    if(l1==NULL)
            p_last->next=l2;
    if(l2==NULL)
            p_last->next=l1;

    
    return preHead.next;
}
