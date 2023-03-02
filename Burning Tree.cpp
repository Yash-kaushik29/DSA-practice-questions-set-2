class Solution {
  public:
    Node* mapping(Node* root, int target, map<Node*, Node*>& m) {
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        m[root] = NULL;
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if(front->data == target) {
                res = front;
            }
            
            if(front->left) {
                m[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right) {
                m[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*>& m) {
         
         map<Node*,bool> visited;
         queue<Node*> q;
         int time = 0;
         
         q.push(root);
         visited[root] = true;
         
         while(!q.empty()) {
             
             int size = q.size();
             bool flag = 0;
             for(int i=0; i<size; i++) {
                 
                 Node* front = q.front();
                 q.pop();
                 
                 if(front->left && !visited[front->left]) {
                     flag = 1;
                     q.push(front->left);
                     visited[front->left] = true;
                 }
                 
                 if(front->right && !visited[front->right]) {
                     flag = 1;
                     q.push(front->right);
                     visited[front->right] = true;
                 }
                 if(m[front] && !visited[m[front]]) {
                     flag = 1;
                     q.push(m[front]);
                     visited[m[front]] = true;
                 }
             }
             if(flag == 1) {
                 time++;
             }
         }
         return time;
    }
  
    int minTime(Node* root, int target) 
    {
        // 1. Create child to parent mapping
        // 2. Find target node
        // 3. Burn the tree
        
        map<Node*, Node*> m;
        
        Node* targetNode = mapping(root, target, m);
        return burnTree(targetNode, m);
        
    }
};
