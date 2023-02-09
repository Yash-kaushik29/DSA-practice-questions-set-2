class Solution
{
    public:
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
    
    void insertAtTail(Node* &head, Node* &tail, int digit) {
        Node* temp = new Node(digit);
        
        if(head == NULL) {
            head = temp;
            tail = temp;
            return ;
        }
        else {
            tail->next = temp;
            tail = tail->next;
            return ;
        }
    }
    
    Node* add(Node* first, Node* second)  {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1=0,val2=0;
            
            if(first != NULL)
            val1 = first->data;
            
            if(second != NULL)
            val2 = second->data;
            
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            if(first != NULL)
               first = first->next;
               
            if(second != NULL)
               second = second->next;
        }
        return ansHead;
    }
    
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // Step 1 - Reverse the LLs
        first = reverse(first);
        second = reverse(second);
        
        Node* ans = add(first,second);    
        ans = reverse(ans);
        
        return ans;
    }
};
