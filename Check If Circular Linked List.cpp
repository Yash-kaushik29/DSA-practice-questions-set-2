bool isCircular(Node *head)
{
   // Your code here
   Node* temp=head->next;
   
   if(head==NULL)
   return 0;
   
   while(temp!=NULL && temp!=head) {
       temp=temp->next;
   }
   
   if(temp == head)
   return 1;
   
   return 0;
}
