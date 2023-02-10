Node* merge(Node*a, Node* b) {
    if(a == NULL)
      return b;
    
    if(b == NULL)
      return a;
    
    Node* result;
    if(a->data < b->data) {
        result = a;
        a->bottom = merge(a->bottom,b);
    }
    else {
        result = b;
        b->bottom = merge(a,b->bottom);
    }
    result->next = NULL;
    return result;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL)
      return root;
   
   return merge(root,flatten(root->next));
}
