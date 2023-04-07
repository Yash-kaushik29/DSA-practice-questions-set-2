class Solution
{
public:
    bool found(Node* root, int k) {
        if(!root) return false;
        
        if(root->data == k) return true;
        
        if(k > root->data) found(root->right, k);
        else found(root->left, k);
    }

    void solve(Node* root1, Node* root2, int x, int& c) {
        if(!root1) return ;
        
        solve(root1->left, root2, x, c);
        if(found(root2, x-root1->data)) c++;
        solve(root1->right, root2, x, c);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        int c=0;
        solve(root1, root2, x, c);
        return c;
    }
};
