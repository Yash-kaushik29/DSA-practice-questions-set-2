class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        if(!root1 and !root2) 
          return true;
        if(!root1 or !root2)
          return false;
          
        queue<Node*> q1,q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while(1) {
            int size1 = q1.size();
            int size2 = q2.size();
            
            if(size1==0 and size2==0) {
                break;
            }
            else if(size1 != size2) {
                return false;
            }
            
            vector<int> level1,level2;
            
            while(size1--) {
                
                Node* front1 = q1.front();
                q1.pop();
                level1.push_back(front1->data);
                if(front1->left) {
                    q1.push(front1->left);
                }
                if(front1->right) {
                    q1.push(front1->right);
                }
                
                Node* front2 = q2.front();
                q2.pop();
                level2.push_back(front2->data);
                if(front2->left) {
                    q2.push(front2->left);
                }
                if(front2->right) {
                    q2.push(front2->right);
                }
            }
            
            sort(level1.begin(),level1.end());
            sort(level2.begin(),level2.end());
            if(level1 != level2)
                return false;
        }
        
        return true;
    }
};
