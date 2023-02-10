class Solution
{
    public:
    Node* reverse(Node* head) {
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
     
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        
        int max = head->data;
        Node* temp = head;
        Node* prev = head;
        head = head->next;
        
        while(head) {
            if(head->data >= max) {
                max = head->data;
                prev = head;
                head = head->next;
            }
            else {
                prev->next = head->next;
                head = prev->next; 
            }
        }
        head = reverse(temp);
        return head;
        
    }
    
};
