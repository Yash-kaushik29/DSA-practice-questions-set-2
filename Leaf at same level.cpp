class Solution{
  public:
    /*You are required to complete this method*/
    void solve(Node* root, int h, int& l, bool& ans) {
        if(root==NULL) return ;
        if(ans==0) return ;
        
        if(!root->left and !root->right) {
            if(l==-1) l=h;
            else {
                if(h!=l) ans=0; 
            }
            return ;
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
