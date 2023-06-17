vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> level;
    if(root==NULL) return level;
       
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        
        level.push_back(front->data);
        
        if(front->right) q.push(front->right);
        if(front->left) q.push(front->left);
    }
    
    reverse(level.begin(), level.end());
    return level;
}
