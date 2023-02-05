class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        // Base call
        if(head == NULL)
        return head;

        // Step-1 : reverse first K nodes
        struct node* curr=head;
        struct node* Next=NULL;
        struct node* prev=NULL;
        int count=0;

        while(curr != NULL && count < k) {
           Next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=Next;
           count++;
          }

        // Step-2 : recursive call for further nodes
        head->next = reverse(Next,k);

        // Step-3 : output: return reverse list
        return prev;
    }
};
