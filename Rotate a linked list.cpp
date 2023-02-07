class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* tail=head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        
        while(k) {
            Node* temp = head;
            head = head->next;
            tail->next = temp;
            temp->next = NULL;
            tail = tail->next;
            k--;
        }
        
        return head;
    }
};
  
