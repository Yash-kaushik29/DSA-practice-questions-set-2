vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> level;
       if(root==NULL) return level;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            for(int i=0; i<n; i++){
               Node *node=q.front();
               q.pop();
               if(node->right!=NULL) q.push(node->right);
               if(node->left!=NULL) q.push(node->left);
              
               level.push_back(node->data);
            }
        }
        reverse(level.begin(),level.end());
        return level;
}
