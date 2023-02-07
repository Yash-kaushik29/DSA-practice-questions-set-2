Node *removeDuplicates(Node *head)
{
 // your code goes here
     if(head==NULL)
     return NULL;
     
     Node* curr=head;
     
     while(curr != NULL) {
         
         if((curr->next != NULL) && (curr->data == curr->next->data)) {
             Node* update=curr->next->next;
             Node* nodeToBeDeleted = curr->next;
             delete(nodeToBeDeleted);
             curr->next=update;
         }
         
         else {
             curr = curr->next;
         }
     }
     return head;
}
