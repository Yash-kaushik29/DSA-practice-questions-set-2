void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if(head == NULL)
    return ;
    Node * slow = head;
    Node * fast = head;
    while(fast->next != head){
        fast = fast->next;
        if(fast->next != head){
        fast = fast->next;
         slow = slow->next;
         }
    }
   fast->next = slow->next;
   Node * temp =  slow->next;
   slow->next = head;
   *head1_ref = head;
   *head2_ref = temp;
}
