class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        
        if(head==NULL || head->next==NULL)
        return NULL;

        while(fast != NULL) {
            fast=fast->next;
            
            if(fast != NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
            
            if(slow == fast) {
                 while(temp!=slow) {
                 slow=slow->next;
                 temp=temp->next;
                 }
                 return temp;
            }   
        }

        return NULL;
    }
};
