// Iterative approach

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL)
        return head;
        
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=NULL;
        
        while(curr!=NULL) {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
};


// Recursive approach

{
    public:
    //Function to reverse a linked list.
    struct Node* reverse(Node* &head, Node* curr, Node* prev) {
        
        if(curr==NULL) {
            head=prev;
            return head;
        }
        
        Node* forward=curr->next;
        reverse(head,forward,curr);
        
        curr->next=prev;
    }
    
    
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL)
        return head;
        
        Node* prev=NULL;
        Node* curr=head;
        
        reverse(head,curr,prev);
        return head;
    }
    
};


// 3rd approach

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverse(Node* head) {
        
        // base case 
         if(head==NULL || head->next==NULL)
         return head;
         
         Node* temp=reverse(head->next);
         
         head->next->next=head;
         head->next=NULL;
         return temp;
        
    }
    
    
    struct Node* reverseList(struct Node *head)
    {
        // code here
        
        return reverse(head);
    
    }
    
};
