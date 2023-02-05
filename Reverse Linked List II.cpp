class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right || head == NULL)
        return head;
        
        ListNode dummy(0);
        dummy.next=head;
        ListNode* temp=&dummy;
        int pos=1;

        while(pos<left) {
           temp=temp->next;
           pos++;
        }
        auto workingptr=temp->next;

        while(left<right) {
            auto extractedNode=workingptr->next;
            workingptr->next=extractedNode->next;
            extractedNode->next=temp->next;
            temp->next=extractedNode;
            left++;
        }
    
        return dummy.next;
    }
};
