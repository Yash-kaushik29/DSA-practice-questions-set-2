class Solution{
    public:
    
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
         int pos=1;
         Node* ans=head;
         Node* p=head;
         
         if(head==NULL) return -1;
         
         int len=0;
         while(p!=NULL) {
           p=p->next;
           len++;
         }

         while(pos<((len/2) + 1)) {
           pos++;
           ans=ans->next;
         }
         int value=ans->data;
         return value;
       }
};
