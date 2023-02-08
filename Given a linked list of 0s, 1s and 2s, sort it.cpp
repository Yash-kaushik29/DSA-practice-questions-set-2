class Solution
{
    public:
    
    void insertTail(Node* &tail, Node* curr)  {
        
        tail->next = curr;
        tail = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
        
        // create 3 new lists for 0,1,2 respectively
        while(curr != NULL) {
            int value = curr->data;
            
            if(value == 0)
            insertTail(zeroTail,curr);
            
            else if(value == 1)
            insertTail(oneTail,curr);
            
            else 
            insertTail(twoTail,curr);
            
            curr = curr->next;
        }
        
        // merging all the LL
        
        if(oneHead->next != NULL)  {          // 1's list is empty
            zeroTail->next = oneHead->next;
        }
        
        else {
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        // head setup
        head = zeroHead->next;
        
        // delete dummy nodes
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return head;
    }
};
