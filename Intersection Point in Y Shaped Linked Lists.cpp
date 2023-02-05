class Solution
{
public:
    int getlength(Node* head) {
        Node* p=head;
        int len=0;
        
        while(p!=NULL) {
            len++;
            p=p->next;
        }
        return len;
    }


    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int l1=getlength(head1);
        int l2=getlength(head2);
        
        Node* temp1=head1;
        Node*temp2=head2;
        
        if(l1>l2) {
            for(int i=0; i<l1-l2; i++) {
                temp1=temp1->next;
            }
        }
        else {
            for(int i=0; i<l2-l1; i++) {
                temp2=temp2->next;
            }
        }
        
        while(temp1!=temp2) {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return temp1->data;
    }
};
