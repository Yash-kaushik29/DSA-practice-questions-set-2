Node* solve(Node* root, int& k, int node) {
    if(root == NULL) {
        return NULL;
    }
    
    if(root->data == node) {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns || rightAns) {
        k--;
        if(k <= 0) {
            k = INT_MIN;
            return root;
        }
        return leftAns ? leftAns : rightAns; 
    }
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    
    return (ans==NULL || ans->data==node) ? -1 : ans->data;
}
