class Solution
{
    public:
    
    Node* reverse(Node* head) {
         if(head==NULL || head->next==NULL)
         return head;
         
         Node* temp=reverse(head->next);
         
         head->next->next=head;
         head->next=NULL;
         return temp;
    }
    
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        Node* curr = head;
        
        while(curr != NULL) {
            
            if(curr->next == NULL && curr->data == 9) {
                curr->data = 1;
                Node* temp = new Node(0);   // adding new node(0) at the last (9 : 1->0)
                temp->next = head;
                head = temp;
                curr = curr->next;
            }
            
            else if(curr->data == 9) {
                curr->data = 0;
                curr = curr->next;
            }
            
            else  {
                curr->data +=1;
                curr = curr->next;
                break;
            }
        }
        head = reverse(head);
        return head;
        
    }
};
