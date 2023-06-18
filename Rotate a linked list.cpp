// Approach 1
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

// Approach 2
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* temp = head;
        
        while(k > 1) {
            temp = temp->next;
            k--;
        }
        
        if(temp->next == NULL) return head;
        
        Node* newHead = temp->next;
        temp->next = NULL;
        
        temp = newHead;
        while(temp->next) {
            temp = temp->next;
        }
        
        temp->next = head;
        return newHead;
    }
};
  
