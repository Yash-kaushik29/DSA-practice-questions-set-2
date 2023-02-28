class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int> > > nodes;
        queue<pair<Node*,pair<int,int> > > q; // pair of hor. distance and level of binary tree
        vector<int> ans;
        
        if(root == NULL) 
          return ans;
         
        q.push(make_pair(root,make_pair(0,0))); 
        
        while(!q.empty()) {
            pair<Node*,pair<int,int> > temp = q.front();
            q.pop();
            
            Node* frontnode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            nodes[hd][level].push_back(frontnode->data);
            
            if(frontnode->left)
              q.push(make_pair(frontnode->left, make_pair(hd-1, level+1)));
            
            if(frontnode->right)
              q.push(make_pair(frontnode->right, make_pair(hd+1, level+1)));  
        }
        for(auto i: nodes) {
            for(auto j: i.second) {
                for(auto k: j.second)
                  ans.push_back(k);
            }
        }
        
        return ans;
    }
};
