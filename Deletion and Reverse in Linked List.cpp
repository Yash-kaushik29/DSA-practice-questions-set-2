void deleteNode(struct Node **head, int key)
{

// Your code goes here
   Node* cur = *head;
   Node* temp = cur->next;
   
   while(temp->data != key) {
       temp = temp->next;
       cur = cur->next;
   }
   
   cur->next = temp->next;    
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{

// Your code goes here
  Node *prev=NULL, *curr=*head_ref;
    while(curr->next){
        Node *forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    curr->next=prev;
    *head_ref=prev;
}
