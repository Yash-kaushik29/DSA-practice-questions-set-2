int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* fast = head;
    Node* slow = head;
    
    if(head->next == NULL)
    return 0;
    
    while(fast != NULL) {
        fast = fast->next;
        
        if(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
        }
        
        if(fast == slow)
        break;
    }
    
    if(fast != slow)
    return 0;
    
    slow = slow->next;
    int count = 1;
    
    while(slow != fast) {
        count++;
        slow = slow->next;
    }
    return count;
 }
