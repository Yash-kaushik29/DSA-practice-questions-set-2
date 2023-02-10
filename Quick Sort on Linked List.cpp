node* getTail(node* head) {
    node* temp = head;
    while(temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

node* partition(node* head, node* tail) {
    node* pivot = head;
    node* cur = head->next,*prev = head;
    
    while(cur != tail->next) {
        if(pivot->data > cur->data) {
            swap(prev->next->data, cur->data);
            prev = prev->next;
        }
        cur = cur->next;
    }
    swap(prev->data, pivot->data);
    return prev;
}


void solve(node* head, node* tail) {
    if(head == nullptr || tail == nullptr || head == tail)
    return ;
    
    node* pivot = partition(head,tail);
    solve(head,pivot);
    solve(pivot->next,tail);
}

//you have to complete this function
void quickSort(struct node **headRef) {
    
    node* head = *headRef;
    if(head == nullptr || head->next == nullptr) 
    return ;
    
    node* tail = getTail(head);
    solve(head,tail);
}
