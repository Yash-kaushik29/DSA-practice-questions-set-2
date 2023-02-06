class Solution
{
    public:
    
    Node * detectLoop(Node *head){
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next; 
            if(slow==fast){
                return slow;
            }
        }
        return NULL; 
    }
    void removeLoop(Node* head)
    {
        // code here
        
        Node *meet=detectLoop(head);
        Node *temp=head; 
        if(meet!=NULL){
            while(temp!=meet){
                temp=temp->next;
                meet=meet->next;
            }
            while(meet->next!=temp)
                meet=meet->next;
            meet->next=NULL;
        }
    }   
};
