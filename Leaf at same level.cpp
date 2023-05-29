class Solution{
  public:
    void solve(Node* root, int h, int& l, bool& ans) {
        if(root == NULL) return ;
        if(ans == 0) return ;
        
        if(!root->left && !root->right) {
            //For first leaf node 
            if(l==-1) {
                l=h;
            }
            // for further leaf nodes, check for same level
            else if(l!=h) {
                ans=0;
            }
        }
        solve(root->left, h+1, l, ans);
        solve(root->right, h+1, l, ans);
    }
    
    
    bool check(Node *root)
    {
        int level=-1;
        int h=0;
        bool ans=1;
        
        solve(root, h, level, ans);
        
        return ans;
    }
};
