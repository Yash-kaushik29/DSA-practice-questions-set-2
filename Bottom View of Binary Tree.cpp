class Solution {
  public:
    vector <int> bottomView(Node *root) {
       
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<pair<Node*, int> > q;
        map<int, int> mp;
        
        q.push({root,0});
        
        while(!q.empty()) {
            Node* frontNode = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            mp[hd] = frontNode->data;
            
            if(frontNode->left) {
                q.push({frontNode->left, hd-1});
            }
            if(frontNode->right) {
                q.push({frontNode->right, hd+1});
            }
        }
        
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
