class Solution{
public:
    
    Node* divide(int N, Node *head){
        // code here
        
        // head2 and tail2 are pointers for even data
        // head1 and tail1 are pointers for odd data
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* tail1 = NULL;
        Node* tail2 = NULL;
        
        while(head) {
            if(head->data & 1) {
                if(head1 == NULL) {
                    head1 = head;
                    tail1 = head;
                }
                else {
                    tail1->next = head;
                    tail1 = head;
                }
            }
            else {
                if(head2 == NULL) {
                    head2 = head;
                    tail2 = head;
                }
                else {
                    tail2->next = head;
                    tail2 = head;
                }
            }
            head = head->next;
        }
        if(head2) tail2->next = head1;
        if(head1) tail1->next = NULL;
        
        if(head2) 
        return head2;
        
        return head1;
    }
};
