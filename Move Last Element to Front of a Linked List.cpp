class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        ListNode* curr = head;
        ListNode* temp = head->next;
        
        if(head->next == NULL)
        return head;
        
        while(temp->next != NULL) {
            temp = temp->next;
            curr = curr->next;
        } 
        
        temp->next = head;
        head = temp;
        curr->next = NULL;
        
        return head;
    }
};
