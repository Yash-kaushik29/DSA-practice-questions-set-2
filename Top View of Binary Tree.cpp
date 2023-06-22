class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root ==NULL) 
          return ans;
        
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()) {
           pair<Node*,int> temp = q.front();
           q.pop();
           
           Node* frontnode = temp.first;
           int hd = temp.second;
           
           // if ans element is present at hd level ,then do nothing else store the node at that hd level
           if(m.find(hd) == m.end()) {
               m[hd] = frontnode->data;
           }
           
           if(frontnode->left)
              q.push(make_pair(frontnode->left, hd-1));
              
           if(frontnode->right)
              q.push(make_pair(frontnode->right, hd+1));      
        }
        
        for(auto i: m) {
            ans.push_back(i.second);
        }
         return ans;
    }

};
