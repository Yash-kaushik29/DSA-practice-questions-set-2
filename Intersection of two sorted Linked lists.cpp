Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node* cur1 = head1;
    Node* cur2 = head2;
    Node* head = NULL;
    Node* cur = NULL;
    
    while(cur1 != NULL && cur2 != NULL) {
        
        if(cur1->data == cur2->data) {
            Node* temp = new Node(cur1->data);
            
            if(head == NULL) {
                head = temp;
                cur = temp;
            }
            else   {
                cur->next = temp;
                cur = cur->next;
            }
            
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        else if(cur1->data < cur2->data) 
        cur1 = cur1->next;
        
        else 
        cur2 = cur2->next;
    }
    
    return head;
    
 }
