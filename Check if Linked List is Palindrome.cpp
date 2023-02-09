class Solution{
  public:
    Node* getMid(Node* head) {
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
  
  
    Node* reverse(Node* head)  {
        Node* cur = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(cur != NULL)  {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next == NULL)
        return true;
        
        // Step 1 - Find the middle node
        Node* middle = getMid(head);
        
        // Step 2 - Reverse list after middle
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        // step 3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;
        
        while(head2 != NULL) {
            if(head1->data != head2->data)
            return false;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // Step 4 - Reverse the LL agin to obtain the original LL
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
    }
};
